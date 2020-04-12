//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        int n = 1 << nums.size();
        n --;
        for(int i = 0;i <= n;i ++){
            vector<int> tmp;
            int t = i;
            for(int j = 0;j < nums.size() && t;j ++){
                if(t % 2 == 1){
                    tmp.push_back(nums[j]);
                }
                t /= 2;
            }
            res.push_back(tmp);
        }
        return res;
        /*
         *
            19:45	info
			解答成功:
			执行耗时:4 ms,击败了74.55% 的C++用户
			内存消耗:6.9 MB,击败了100.00% 的C++用户
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
