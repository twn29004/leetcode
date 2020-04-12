//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 说明： 
//
// 
// 所有数字（包括目标数）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
// 
//
// 示例 2: 
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//] 
// Related Topics 数组 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> res;
public:
    void BackTrack(vector<int>& candidates,int target,int& sum,vector<int> tmp,int index){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(tmp);
            return;
        }
        int tmp_sum = sum;
        for(int i = index;i < candidates.size();i ++){
            if(index != i && i != 0 && candidates[i] == candidates[i - 1]){    // 防止每一层的结果
                continue;
            }
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            BackTrack(candidates,target,sum,tmp,i + 1);
            sum = tmp_sum;
            tmp.erase(tmp.end() - 1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        if(candidates.size() == 0 || candidates[0] > target){
            return res;
        }
        vector<int> tmp;
        int sum = 0;
        BackTrack(candidates,target,sum,tmp,0);
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
