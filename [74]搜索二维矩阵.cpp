//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性： 
//
// 
// 每行中的整数从左到右按升序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 示例 1: 
//
// 输入:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 13
//输出: false 
// Related Topics 数组 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int len;
public:

    bool BinarySearch(int left,int right,vector<vector<int>>& matrix, int target){
        if(left >= right){
            if(matrix[left / len][left % len] == target){
                return true;
            }
            return false;
        }

        int mid = (left + right) / 2;
        if(target == matrix[mid / len][mid % len]){
            return true;
        }
        if(matrix[mid / len][mid % len] > target){
            return  BinarySearch(left,mid - 1,matrix,target);
        }else{
            return BinarySearch(mid + 1,right,matrix,target);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 就是把left,mid转化为对应的坐标就好了
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        len = matrix[0].size();
        return BinarySearch(0,matrix.size() * matrix[0].size() - 1,matrix,target);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
