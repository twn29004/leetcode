//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须原地修改，只允许使用额外常数空间。 
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 
//1,2,3 → 1,3,2 
//3,2,1 → 1,2,3 
//1,1,5 → 1,5,1 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        next_permutation(nums.begin(), nums.end());
        return ;
         */
        /*
         * 	info
			解答成功:
			执行耗时:4 ms,击败了86.64% 的C++用户
			内存消耗:6.7 MB,击败了100.00% 的C++用户
         */
        //这个解法有点过分哈


       //算法的基本流程是这样的。
       /*
        * 1. 从右往左找，找到第一个nums[i] > nums[i - 1]
        * 2. 从右到左找到第一个大于nums[i - 1]的数nums[j]
        * 3. 交换nums[j]和nums[i-1]的位置
        * 4. 将nums[i]之后的元素
        */
       //第一步
       if(nums.size() < 2) return;
       int i = nums.size() - 1;
       //注意这里应该把i > 0放在前面，不然当i = 0的时候会出现nums[0-1]的未定义行为
       //还有注意这里nums[i]和nums[i-1]的大小关系，特殊情况就是出现全部相等的时候，这样就会导致后面的第二步出现问题
       while( i > 0 && nums[i] <= nums[i - 1]){
           i --;
       }
       //就是最大的情况
       if(i == 0){
           reverse(nums.begin(),nums.end());
           return;
       }
       //第二步
       int j = nums.size() - 1;
       while(j >= 0 && nums[j] <= nums[i - 1]){
           j --;
       }
       //第三步
       swap(nums[i - 1],nums[j]);
       //第四步
       reverse(nums.begin() + i,nums.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
