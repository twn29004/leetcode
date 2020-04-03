//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。 
//
// 返回被除数 dividend 除以除数 divisor 得到的商。 
//
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2 
//
// 
//
// 示例 1: 
//
// 输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = truncate(3.33333..) = truncate(3) = 3 
//
// 示例 2: 
//
// 输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = truncate(-2.33333..) = -2 
//
// 
//
// 提示： 
//
// 
// 被除数和除数均为 32 位有符号整数。 
// 除数不为 0。 
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。 
// 
// Related Topics 数学 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int dividend, int divisor) {

        //对于越界溢出这个问题还是不能很好的结局。先留着以后再看，本题中使用long long 显然时不符合题目要求的。

        if(dividend == 0 || (abs(dividend) < abs(divisor) && abs(dividend) > 0)) return 0;   //对于特殊情况的处理

        long long  tmp1,tmp2;
        tmp1 = abs(divisor);
        tmp2 = tmp1;
        long long cnt = 1;
        bool flag;

        if(dividend == INT_MIN){
            dividend ++;
        }

        while(tmp1 <= abs(dividend)){
            tmp2 = tmp1;
            tmp1 += tmp1;
            cnt += cnt;
        }

        cnt /= 2;

        while(tmp2 <= abs(dividend)){
            tmp2 += abs(divisor);
            cnt ++;
        }
        cnt --;



        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0){
            cnt *= -1;
        }
        if(cnt > INT_MAX || cnt < INT_MIN){
            return INT_MAX;
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
