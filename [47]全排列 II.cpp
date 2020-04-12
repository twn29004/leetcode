//给定一个可包含重复数字的序列，返回所有不重复的全排列。 
//
// 示例: 
//
// 输入: [1,1,2]
//输出:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//] 
// Related Topics 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> res;
    vector<bool> isUsed;
public:

    void BackTrack(vector<int> nums,int index,vector<bool>& isUsed, vector<int> tmp){
       if(index == nums.size()){
           res.push_back(tmp);
           return;
       }
       int len = nums.size();
       for(int i = 0;i < len;i ++){
           if(isUsed[i]){
               continue;
           }
           if(i > 0 && nums[i] == nums[i - 1] && !isUsed[i - 1]){ // 如果i - 1已经使用过的话，那么在他的那一层之后他就变成false了
               continue;
           }
           tmp.push_back(nums[i]);
           isUsed[i] = true;
           BackTrack(nums,index + 1,isUsed,tmp);
           isUsed[i] = false;
           tmp.erase(tmp.end() - 1);
       }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i = 0;i < nums.size();i ++){   // 初始化
            isUsed.push_back(false);
        }
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        BackTrack(nums,0,isUsed,tmp);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
