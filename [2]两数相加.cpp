//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//AC


class Solution {
public:
    ListNode* l3 = new ListNode(0);
    ListNode* M = l3;
    bool carry = false;     //判断是否有进位

    void add(ListNode* l){
        while(l && carry){
            ListNode* tmp =  new ListNode((l->val + carry) % 10);
            M->next = tmp;
            if(l->val + carry >= 10)
                carry = true;
            else
                carry = false;
            l = l->next;
            M = M ->next;
        }
        if(l){
            M->next = l;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        while(p && q){
           ListNode* tmp = new ListNode((l1->val + l2->val + carry) % 10);
           M->next = tmp;
           if(l1->val + l2->val + carry >= 10)
               carry = true;
           else
               carry = false;
           l1 = l1->next;
           l2 = l2->next;
           M = M->next;
           p = l1;
           q = l2;
        }

        if(l1 == NULL) {
            add(l2);
        }else if(l2 == NULL){
            add(l1);
        }

        if(carry){
            ListNode* tmp = new ListNode(carry);
            M->next = tmp;
        }

        return l3->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
