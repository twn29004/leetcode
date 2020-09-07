//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
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

    bool DFS(TreeNode* left,TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }
        if(left == NULL && right != NULL){
            return false;
        }
        if(left != NULL && right == NULL){
            return false;
        }
        if(left->val != right->val){
            return false;
        }else{
            return (DFS(left->left,right->right) && DFS(left->right,right->left));
        }
    }

    bool isSymmetric(TreeNode* root) {
        return DFS(root,root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
