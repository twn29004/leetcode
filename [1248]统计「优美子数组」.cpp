//给你一个整数数组 nums 和一个整数 k。 
//
// 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。 
//
// 请返回这个数组中「优美子数组」的数目。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [1,1,2,1,1], k = 3
//输出：2
//解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
// 
//
// 示例 2： 
//
// 输入：nums = [2,4,6], k = 1
//输出：0
//解释：数列中不包含任何奇数，所以不存在优美子数组。
// 
//
// 示例 3： 
//
// 输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//输出：16
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 50000 
// 1 <= nums[i] <= 10^5 
// 1 <= k <= nums.length 
// 
// Related Topics 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ods[50000+5];
        int odscnt = 0;
        // 找出所有奇数的位置
        for(int i = 0;i < nums.size();i ++) {
            if (nums[i] % 2) {
                ods[odscnt] = i;
                odscnt ++;
            }
        }
        // 没有奇数或者奇数的数目不够
        if(odscnt < k){
            return 0;
        }

        int cnt = 0;
        // 不妨先处理一下第一个
        int left;
        int right = left;

        for(int i = 0;i + k - 1 < odscnt;i ++){
           left = i;
           right = left + k - 1;

           int t1 = left - 1 >= 0 ? ods[left] - ods[left - 1] - 1 : ods[left] - 0;
           int t2 = right + 1 < odscnt ? ods[right + 1] - ods[right] - 1 : nums.size() - 1 - ods[right];

           cnt += (t1 + t2 + t1 * t2 + 1);
        }

        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
