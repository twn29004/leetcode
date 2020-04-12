//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。 
//
// 示例 1: 
//
// 输入: "(()"
//输出: 2
//解释: 最长有效括号子串为 "()"
// 
//
// 示例 2: 
//
// 输入: ")()())"
//输出: 4
//解释: 最长有效括号子串为 "()()"
// 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
       // 使用动态规划的方法
       /*
        * 设置一个dp数组。dp[i]表示以s[i]结尾的字串的最长有效括号。将字符数组全部初始化为0，因为刚开始字串中只包含‘(’ or ‘)’.
        * 注意这里的结尾是字串一定包含下标为s[i]的字符。注意是一定包含。所以有了下面的情况:
        *
        * 如果s[i]是'(',则这个字串连合法串都不是，所以不需要对齐进行判断
        *
        * 下面讨论s[i]为')'的情况。
        * (1) s[i] = ')' && s[i - 1] = '('，则dp[i] = dp[i - 1] + 2
        * (2) s[i] = ')' && s[i - 1] = ')' && s[i - dp[i - 1] - 1] = '(',即前面的那个字串能够构成一个合法串。
        *     dp[i] = dp[i - dp[i - 1] -2] + dp[i - 1] + 2;
        *
        * 同时还要注意各种边界条件
        */

       const int len = s.length();
       vector<int> dp(len,0);
       int res = 0;
       for(int i = 1;i < len;i ++){
           if(s[i] == ')'){
               if(s[i - 1] == '('){
                   dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
               }else{
                   int tmp = i - dp[i - 1] - 1;
                   if(tmp >= 0 && s[tmp] == '('){
                       dp[i] = dp[i - 1] + (tmp - 1 >= 0 ? dp[tmp - 1] : 0) + 2;
                   }
               }
       }
           res = max(res,dp[i]);
       }

       return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
