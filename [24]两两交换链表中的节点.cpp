//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例: 
//
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;  //每次都要考虑特殊情况

        ListNode* h1 = head;
        ListNode* h2 = h1->next;
        ListNode* h3 = h2->next;
        ListNode* h = h2;


        while(h3 && h3->next){
            //转向
            h1->next = h3->next;
            h2->next = h1;
            //移动
            h1 = h3;
            h2 = h3->next;
            h3 = h2->next;
        }

        if(h3 == NULL){   //说明最后的还没交换
            h2->next = h1;
            h1->next = NULL;
        }
        else if(h3->next == NULL){   //注意使用else，因为前面那个不满足，这个一定不满足，造成错觉
            h1->next = h3;
            h2->next = h1;
        }
        return h;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
