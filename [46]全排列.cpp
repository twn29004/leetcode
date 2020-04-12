//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void BackTrack(vector<int>& nums,int index,vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size();i ++){
            swap(nums[index],nums[i]);
            BackTrack(nums,index + 1,res);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() <= 1){
            res.push_back(nums);
            return res;
        }
        sort(nums.begin(),nums.end());
        BackTrack(nums,0,res);
        return res;
    }
    /*
     * info
			解答成功:
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:7.1 MB,击败了100.00% 的C++用户
     */
};
//leetcode submit region end(Prohibit modification and deletion)
