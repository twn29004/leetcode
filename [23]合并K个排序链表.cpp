//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。 
//
// 示例: 
//
// 输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6 
// Related Topics 堆 链表 分治算法


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
    //可以先将两行合并，然后返回，在不断的合并，类似于归并排序

    ListNode* MergeSort(vector<ListNode*>& lists,int begin,int end){
        if(begin >= end) return lists[begin];
        //分割
        int mid = (begin + end) / 2;
        ListNode* left;
        ListNode* right;

        left = MergeSort(lists,begin,mid);
        right = MergeSort(lists,mid + 1,end);

        //合并
        ListNode* mov = new ListNode(0);
        ListNode* head = mov;
        while(left && right){
            if(left->val < right->val){
                mov->next = new ListNode(left->val);
                mov = mov->next;
                left = left->next;
            }else{
                mov->next = new ListNode(right->val);
                mov = mov->next;
                right = right->next;
            }
        }

        while(left){
            mov->next = new ListNode(left->val);
            mov = mov->next;
            left = left->next;
        }

        while(right){
            mov->next = new ListNode(right->val);
            mov = mov->next;
            right = right->next;
        }

        return head->next;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        return MergeSort(lists,0,lists.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
