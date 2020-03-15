//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 
//
// 示例 1: 
//
// 输入: 121
//输出: true
// 
//
// 示例 2: 
//
// 输入: -121
//输出: false
//解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3: 
//
// 输入: 10
//输出: false
//解释: 从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 进阶: 
//
// 你能不将整数转为字符串来解决这个问题吗？ 
// Related Topics 数学


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        char str[20];
        sprintf(str,"%d",x);  //将数字转化为字符
        int t = 0;
        while(str[t] != '\0') t++;
       for(int i = 0,j = t - 1;i < j;i ++,j --){
               if(str[i] != str[j]) return false;
       }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
