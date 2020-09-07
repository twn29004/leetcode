//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其自底向上的层次遍历为： 
//
// [
//  [15,7],
//  [9,20],
//  [3]
//]
// 
// Related Topics 树 广度优先搜索


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
    vector<vector<int>> res;
public:

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode*> V1;
        vector<TreeNode*> V2;
        if(root){
            V1.push_back(root);
        }else{
            return res;
        }
        while(!V1.empty()){
            vector<int> tmp;
            for(int i = 0;i < V1.size();i ++){
                tmp.push_back(V1[i]->val);
                if(V1[i]->left){
                    V2.push_back(V1[i]->left);
                }
                if(V1[i]->right){
                    V2.push_back(V1[i]->right);
                }
            }
            res.push_back(tmp);
            V1 = V2;
            V2.clear();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
