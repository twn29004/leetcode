//给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。 
//
// 
//
// 示例 1: 
//
// 输入: [1,2,0]
//输出: 3
// 
//
// 示例 2: 
//
// 输入: [3,4,-1,1]
//输出: 2
// 
//
// 示例 3: 
//
// 输入: [7,8,9,11,12]
//输出: 1
// 
//
// 
//
// 提示： 
//
// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int Max = -1,Min = INT_MAX;
        int cnt = 0;
        bool flag = false;

        for(int i = 0;i < nums.size();i ++){
            if(nums[i] > 0){
                flag = true;
                Max = max(Max,nums[i]);
                Min = min(Min,nums[i]);
                cnt ++;
            }
        }

       if(Min > 1 || !flag){    // 没有正数或者说有但是最小值太大了
           return 1;
       }

       if(Max - Min + 1 > cnt){
           return Max + 1;
       }



    }
};
//leetcode submit region end(Prohibit modification and deletion)
