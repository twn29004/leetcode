//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。 
//
// 
//
// 示例 : 
//给定二叉树 
//
//           1
//         / \
//        2   3
//       / \     
//      4   5    
// 
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。 
//
// 
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。 
// Related Topics 树


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

    int dep(TreeNode* root){
        if(root == NULL) return 0;
        int count = 0;
        if(root->left || root->right){
            count ++;
        }
        count += dep(root->left);
        count += dep(root->right);
        return count;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int count = dep(root);
       if(root == NULL){
           return 0;
       }
       if(root->left == NULL || root->right == NULL) return count;
       return count + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
