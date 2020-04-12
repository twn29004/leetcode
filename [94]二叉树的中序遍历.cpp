//给定一个二叉树，返回它的中序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表


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
    vector<int> tmp;
public:
/*
    void Zhong(TreeNode* root){
        if(root == NULL){
            return;
        }
        Zhong(root->left);
        tmp.push_back(root->val);
        Zhong(root->right);
    }
*/
// 递归解法，要的是递归的解法
/* 使用栈来实现。先将root压入栈中，然后开始迭代。每次判断栈是否为空。不为空的话判断栈顶的左儿子是不是空。不是空的话讲其压入栈，是空的话，输出栈顶的值，然后再来判断其右儿子。如果其右儿子为空的话，弹出栈顶元素。
 * 重复判断其右儿子。所以说
 */
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return tmp;
        }
        stack<TreeNode*> S;
       do{
           if(root != NULL){
               S.push(root);
               root = root->left;
           }else{
               tmp.push_back(S.top()->val);
               root = S.top()->right;
               S.pop();
           }
       }while(!S.empty() || root);
       return tmp;
    }
    /*
     * 22:17	info
			解答成功:
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:7.1 MB,击败了100.00% 的C++用户
     */
};
//leetcode submit region end(Prohibit modification and deletion)
