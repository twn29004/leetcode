//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最小深度 2. 
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
public:
    int minDepth(TreeNode* root) {
       vector<TreeNode*>  V1;
       vector<TreeNode*> V2;
       int res = 0;

       if(root){
           V1.push_back(root);
       }else{
           return res;
       }

       while(!V1.empty()){
           res ++;
           for(int i = 0;i < V1.size();i ++){
               if(V1[i]->left == NULL && V1[i]->right == NULL){
                   return res;
               }
               if(V1[i]->left){
                   V2.push_back(V1[i]->left);
               }
               if(V1[i]->right){
                   V2.push_back(V1[i]->right);
               }
           }
           V1 = V2;
           V2.clear();
       }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
