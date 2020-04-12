//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 示例: 
//
// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
// 
// Related Topics 数组 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
        // 先初始化dp[0][j]因为他们只能向右走。
        // 再初始化dp[i][0]因为他们只能向下走

        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }

        const int lie = grid[0].size();
        const int hang = grid.size();

        int dp[hang][lie];
        dp[0][0] = grid[0][0];

        for(int i = 1;i < lie;i ++){
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1;i < hang;i ++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for(int i = 1;i < hang;i ++){
            for(int j = 1;j < lie;j ++){
                dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[hang - 1][lie - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
