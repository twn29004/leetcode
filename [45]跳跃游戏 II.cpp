//给定一个非负整数数组，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。 
//
// 示例: 
//
// 输入: [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 
//
// 说明: 
//
// 假设你总是可以到达数组的最后一个位置。 
// Related Topics 贪心算法 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
        // 每次都选择最长的跳跃，自然是最短
       int ans = 0;
       int max_dis = -1;
       int loc = 0;
       int end = 0;

       for(int i = 0;i < nums.size() - 1;i ++){
           /*
           max_dis = -1;
           for(int j = i + 1;j <= i + nums[i];j ++){
               if(j + nums[j] > max_dis){
                   max_dis = j + nums[j];
                   loc = j;
               }
           }
           i = loc - 1;
           ans ++;
            */
           // 上述思路没有问题，但是还可以在优化一下
           max_dis = max(max_dis,nums[i] + i);
           if(i == end){
               end = max_dis;
               ans ++;
           }
       }

       return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
