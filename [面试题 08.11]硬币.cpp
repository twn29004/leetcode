//硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007) 
//
// 示例1: 
//
// 
// 输入: n = 5
// 输出：2
// 解释: 有两种方式可以凑成总金额:
//5=5
//5=1+1+1+1+1
// 
//
// 示例2: 
//
// 
// 输入: n = 10
// 输出：4
// 解释: 有四种方式可以凑成总金额:
//10=10
//10=5+5
//10=5+1+1+1+1+1
//10=1+1+1+1+1+1+1+1+1+1
// 
//
// 说明： 
//
// 注意: 
//
// 你可以假设： 
//
// 
// 0 <= n (总金额) <= 1000000 
// 
// Related Topics 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    const int Mod = 1e9 + 7;

public:
    int waysToChange(int n) {
        vector<int> dp(n + 1);
        if(n == 0){
            return 1;
        }
        dp[0] = 1;
        // 完全背包问题啊，傻逼了
       int coins[4] = {1,5,10,25};

       for(int i = 0;i < 4;i ++){
           int coin = coins[i];
           for(int j = coin;j <= n;j ++){
               dp[j] = (dp[j - coin] + dp[j]) % Mod;
           }
       }
       return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
