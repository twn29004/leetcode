//实现 int sqrt(int x) 函数。 
//
// 计算并返回 x 的平方根，其中 x 是非负整数。 
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
//
// 示例 1: 
//
// 输入: 4
//输出: 2
// 
//
// 示例 2: 
//
// 输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。
// 
// Related Topics 数学 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 注意考虑越界的问题，应使用除法来判断而不是乘法

    int BinarySearch(int target,int left,int right){
        if(left >= right){
            if(target / left >= left && target / (left + 1) < (left + 1)){
                return left;
            }
        }

        int mid = (left + right) / 2;
        if(target / mid >= mid && target / (mid + 1) < (mid + 1)){
            return mid;
        }
        if(target / mid < mid){
            return BinarySearch(target,left,mid - 1);
        }else{
            return BinarySearch(target,mid + 1,right);
        }
    }

    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        if(x <= 3){
            return 1;
        }
        return BinarySearch(x,1,x/2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
