//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。 
//
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。 
//
// 注意：你不能在买入股票前卖出股票。 
//
// 
//
// 示例 1: 
//
// 输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
// 
//
// 示例 2: 
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
// 
// Related Topics 数组 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int res = 0;
        for(int i = 0;i < prices.size();i ++){
            for(int j = i + 1;j < prices.size();j ++){
                res = max(res,prices[j] - prices[i]);
            }
        }
        return  res;
         */ // 不出意外得T了

        //下面是一个复杂度为n的解法
        //记录历史上的最低价，考虑今天卖出能赚多少钱
        /*
        if(prices.size() == 0) return 0;  //不用再忘了这个
        int minPrice = prices[0];  //初始化为第一天的价格
        int res = 0;
        for(int i = 1;i < prices.size();i ++){
            minPrice = min(minPrice,prices[i]);   //更新历史最低价
            res = max(res,prices[i] - minPrice);
        }
        return res;
         */
        //为什么O(n)的复杂度时间还是这么长
        /*			解答成功:
                执行耗时:24 ms,击败了20.93% 的C++用户
                内存消耗:12.7 MB,击败了5.17% 的C++用户
         */

        if(prices.size() == 0) return 0;  //不用再忘了这个
        int minPrice = prices[0];  //初始化为第一天的价格
        int res = 0;
        for(int i = 1;i < prices.size();i ++){
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else{
                int tmp = prices[i] - minPrice;
                if(res < tmp)
                    res = tmp;
            }
        }
        return res;
    }
    /*17:01	info
			解答成功:
			执行耗时:12 ms,击败了49.27% 的C++用户
			内存消耗:12.6 MB,击败了5.17% 的C++用户,没道理内存这么大啊
     */
   // 看来调用函数的代价是巨大的
   //这个耗时波动很大啊，不是很值得参考

};
//leetcode submit region end(Prohibit modification and deletion)
