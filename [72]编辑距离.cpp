//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)

/*
 * 对于动态规划的题目，其核心是找出状态转移方程。这里我们引入dp[i][j]数组，表示的含义是word1[0-i]和word2[0-j]的编辑距离。状态转移方程如下:
 * 如果word1[i] == word2[j].则dp[i][j] = min(dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1]);如果不等的话，前面的结果+1.
 * 原因是无论再前面已经相同的情况下，无论哪种操作都会导致结果+1，那么我们必然是选择最少的那种.
 * dp[i - 1][j - 1] 替换一个字符
 * dp[i - 1][j]     删除一个字符
 * dp[i][j-1]       插入一个字符
 */
class Solution {
public:

    inline int Min(int x,int y,int z){
        return min(min(x,y),z);
    }
    int minDistance(string word1, string word2) {
        const int len1 = word1.length() + 1;
        const int len2 = word2.length() + 1;
        int dp[len1][len2];
        //对dp数组进行初始化。因为显然dp[0][i]必然是等于i，dp[j][0]等于j
        for(int i = 0;i < len1;i ++){
            dp[i][0] = i;
        }
        for(int j = 0;j < len2;j ++){
            dp[0][j] = j;
        }
        //循环计算其他的dp数组的值
        for(int i = 1;i < len1;i ++){
            for(int j = 1;j < len2;j ++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = Min(dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[len1-1][len2-1];

    }
};

/*
        * 14:56	info
           解答成功:
           执行耗时:12 ms,击败了85.10% 的C++用户
           内存消耗:7.5 MB,击败了100.00% 的C++用户
        */
//leetcode submit region end(Prohibit modification and deletion)
