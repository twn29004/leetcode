//给定一个非负整数数组，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 判断你是否能够到达最后一个位置。 
//
// 示例 1: 
//
// 输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
// 
//
// 示例 2: 
//
// 输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
// 
// Related Topics 贪心算法 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 0){
            return false;
        }
        // 每次都选择最长的跳
        int nowLoc = 0;         // 现在位置
        int Max = INT_MIN;
        int tmp_nowLoc = 0;
        while(nowLoc < nums.size() - 1 && nums[nowLoc] != 0){
            //计算现在这个位置能去的最远的位置
            for(int j = 1;j <= nums[nowLoc] && nowLoc + j < nums.size();j ++){
                if(Max < nums[nowLoc + j] + nowLoc + j){
                    Max = nowLoc + j + nums[nowLoc + j];
                    tmp_nowLoc = nowLoc + j;
                }
            }
            nowLoc = tmp_nowLoc;
            Max = INT_MIN;
        }

        if(nowLoc < nums.size() - 1){
            return false;
        }else{
            return true;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
