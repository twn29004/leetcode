//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 
//
// 示例： 
//
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 
//
// 说明： 
//
// 给定的 n 保证是有效的。 
//
// 进阶： 
//
// 你能尝试使用一趟扫描实现吗？ 
// Related Topics 链表 双指针


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //维护两个指针，让他们保持一定的距离
        ListNode* start1 = head;
        ListNode* start2 = head;
        //先拉开距离
        while (n && start1->next){
            start1 = start1->next;
            n --;
        }
        //同时先前移动
        if(start1->next == NULL && n != 0){
            head = head->next;
            return head;
        }
        //删除链表头的时候

        while (start1->next != NULL){
            start1 = start1->next;
            start2 = start2->next;
        }

        //开始删除
        start2->next = start2->next->next;

        return head;

        /*
         * 14:27	info
			解答成功:
			执行耗时:4 ms,击败了87.44% 的C++用户
			内存消耗:6.5 MB,击败了100.00% 的C++用户
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
