//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: candidates = [2,3,6,7], target = 7,
//所求解集为:
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2: 
//
// 输入: candidates = [2,3,5], target = 8,
//所求解集为:
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
// Related Topics 数组 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> res;
public:
    void BackTrack(vector<int>& candidates,int target,int sum,vector<int> tmp,int index){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(tmp);
            return;
        }
        int tmp_sum = sum;
        for(int i = index;i < candidates.size();i ++){
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            BackTrack(candidates,target,sum,tmp,i);
            if(sum + candidates[i] > target){
                break;
            }
            sum = tmp_sum;
            tmp.erase(tmp.end() - 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        if(candidates.size() == 0 || candidates[0] > target){
            return res;
        }
        vector<int> tmp;
        BackTrack(candidates,target,0,tmp,0);
        return res;
    }

    /*
     *
        16:42	info
			解答成功:
			执行耗时:116 ms,击败了10.67% 的C++用户
			内存消耗:18.9 MB,击败了12.66% 的C++用户
     */
};
//leetcode submit region end(Prohibit modification and deletion)
