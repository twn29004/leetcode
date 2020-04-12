//给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//输出: 
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
// 
//
// 示例 2: 
//
// 输入: 
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//输出: 
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//] 
//
// 进阶: 
//
// 
// 一个直接的解决方案是使用 O(mn) 的额外空间，但这并不是一个好的解决方案。 
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。 
// 你能想出一个常数空间的解决方案吗？ 
// 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)

/*
 * 好像并不能通过设置没有的数来构造一种新的状态，原因是给的样例把所有的数都包括了。
 * emmmm,也不对，可以找一个里面没有的数，来作为一种新的状态，当然，如果数组很大的话，这个开销也是很大的
 */

class Solution {
public:

    void Change(vector<vector<int>>& matrix,int hang,int lie){
        for(int j = 0;j < matrix[0].size();j ++){
            matrix[hang][j] = 0;
        }

        for(int i = 0;i < matrix.size();i ++){
            matrix[i][lie] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {


        vector<int> Res;

        for(int i = 0;i < matrix.size();i ++){
            for(int j = 0;j < matrix[0].size();j ++){
                if(matrix[i][j] == 0){
                    Res.push_back(i);
                    Res.push_back(j);
                }
            }
        }

        // 先是行后是列
        for(int i = 0;i < Res.size();i += 2){
            Change(matrix,Res[i],Res[i + 1]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
