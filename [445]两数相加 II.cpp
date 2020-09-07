//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。 
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。 
//
// 
//
// 进阶： 
//
// 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。 
//
// 
//
// 示例： 
//
// 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1;
        vector<int> num2;


        if(l1 == NULL && l2 == NULL){
            ListNode* tmp = NULL;
            return tmp;
        }

        while(l1){
            num1.push_back(l1->val);
            l1 = l1->next;
        }

        while(l2){
            num2.push_back(l2->val);
            l2 = l2->next;
        }

        int i = num1.size() - 1,j = num2.size() - 1;
        int cnt = 0;
        int carry = 0;
        int t = 0;

        t = num1[i] +num2[j];
        ListNode* end = new ListNode(t % 10);
        carry = t / 10;
        ListNode* mv = end;
        i --;
        j --;
        while(i >= 0 && j >= 0){
            t = num1[i] + num2[j] + carry;
            ListNode* tmp = new ListNode(t % 10);
            carry = t / 10;
            tmp->next = mv;
            mv = tmp;
            i --;
            j --;
        }

        while(i >= 0){
            t = num1[i] + carry;
            ListNode* tmp = new ListNode(t % 10);
            carry = t / 10;
            tmp->next = mv;
            mv = tmp;
            i --;
        }

        while(j >= 0){
            t = num2[j] + carry;
            ListNode* tmp = new ListNode(t % 10);
            carry = t / 10;
            tmp->next = mv;
            mv = tmp;
            j --;
        }

        if(carry){
            ListNode* tmp = new ListNode(1);
            tmp->next = mv;
            mv = tmp;
        }

        return mv;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
