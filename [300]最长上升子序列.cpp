//给定一个无序的整数数组，找到其中最长上升子序列的长度。 
//
// 示例: 
//
// 输入: [10,9,2,5,3,7,101,18]
//输出: 4 
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。 
//
// 说明: 
//
// 
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。 
// 你算法的时间复杂度应该为 O(n2) 。 
// 
//
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗? 
// Related Topics 二分查找 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
/*待优化
 * */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        if(nums.size() == 0) return 0;
        const int len = nums.size();
        int F[len];
        for(int i = 0;i < nums.size();i ++) F[i] = 1;
        for(int i = 0;i < nums.size();i ++){
            for(int j = 0;j < i;j ++){
                if(nums[i] > nums[j]){
                    F[i] = max(F[i],F[j] + 1);
                }
            }
        }
        int res = 0;
        for(int i = 0;i < nums.size();i ++){
            res = max(res,F[i]);
        }
        return res;
         */
        //上升方法为n^2的解法

    }
};
//leetcode submit region end(Prohibit modification and deletion)
