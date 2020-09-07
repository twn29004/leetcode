//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 示例: 
//
// 输入: [1,2,3,null,5,null,4]
//输出: [1, 3, 4]
//解释:
//
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
// 
// Related Topics 树 深度优先搜索 广度优先搜索


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> res;
    queue<TreeNode*> V1;

public:
   //应该是使用层序遍历来实现

    vector<int> rightSideView(TreeNode* root) {


       if(root != NULL){
           V1.push(root);
       }else{
           return res;
       }
       int cnt = 1;

       while(!V1.empty()){
           TreeNode* tmp = V1.front();
           res.push_back(tmp->val);
           int tmp_cnt = 0;

           for(int i = 0;i < cnt;i ++){
               tmp = V1.front();
               if(tmp->right){
                   V1.push(tmp->right);
                   tmp_cnt ++;
               }
               if(tmp->left){
                   V1.push(tmp->left);
                   tmp_cnt ++;
               }
               V1.pop();
           }

           cnt = tmp_cnt;
       }
       return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
