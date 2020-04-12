//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL, k = 2
//输出: 4->5->1->2->3->NULL
//解释:
//向右旋转 1 步: 5->1->2->3->4->NULL
//向右旋转 2 步: 4->5->1->2->3->NULL
// 
//
// 示例 2: 
//
// 输入: 0->1->2->NULL, k = 4
//输出: 2->0->1->NULL
//解释:
//向右旋转 1 步: 2->0->1->NULL
//向右旋转 2 步: 1->2->0->NULL
//向右旋转 3 步: 0->1->2->NULL
//向右旋转 4 步: 2->0->1->NULL 
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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
        if(head == NULL){
            return head;
        }
        ListNode* tmp = head;
        ListNode* tmp1 = tmp;
        int cnt = 0;

        while(tmp != NULL){
            cnt ++;
            tmp = tmp->next;
        }

        if(cnt == 1 || k % cnt == 0){
            return head;
        }
        cnt = cnt - k % cnt;   //倒数第cnt个
        cnt --;

        tmp = head;
        while(cnt){
            tmp = tmp->next;
            cnt --;
        }
        cout<<tmp->val<<endl;
        tmp1 = tmp;

        tmp = tmp->next;
        tmp1->next = NULL;
        tmp1 = tmp;

        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        tmp->next = head;

        return tmp1;
         */
        // 先将整个链表和成一个环
        // 然后在合适的地方断开
        if(head == NULL){
            return head;
        }

        ListNode* tmp = head;
        int cnt = 1;
        while(tmp->next){
            tmp = tmp->next;
            cnt ++;
        }
        tmp->next = head;
        cnt = cnt - k % cnt;
        while(cnt > 1){
            head = head->next;
            cnt --;
        }
        tmp = head;
        head = head->next;
        tmp->next = NULL;
        return head;
        /*
         * 17:29	info
			解答成功:
			执行耗时:20 ms,击败了11.46% 的C++用户
			内存消耗:7.2 MB,击败了100.00% 的C++用户
            为什么O(n)的复杂度还是这样
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
