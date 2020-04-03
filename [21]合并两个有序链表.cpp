//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 示例： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
// 
// Related Topics 链表


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mov = new ListNode(-1);  //表示开头
        ListNode* head = mov;
        while (l1 && l2){
            if(l1->val < l2->val){
                mov->next = new ListNode(l1->val);
                mov = mov->next;
                l1 = l1->next;
            }else{
                mov->next = new ListNode(l2->val);
                mov = mov->next;
                l2 = l2->next;
            }
        }

        while(l1){
            mov->next = new ListNode(l1->val);
            mov = mov->next;
            l1 = l1->next;
        }

        while(l2){
            mov->next = new ListNode(l2->val);
            mov = mov->next;
            l2 = l2->next;
        }

        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
