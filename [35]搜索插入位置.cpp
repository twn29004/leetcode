//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 
//
// 你可以假设数组中无重复元素。 
//
// 示例 1: 
//
// 输入: [1,3,5,6], 5
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [1,3,5,6], 2
//输出: 1
// 
//
// 示例 3: 
//
// 输入: [1,3,5,6], 7
//输出: 4
// 
//
// 示例 4: 
//
// 输入: [1,3,5,6], 0
//输出: 0
// 
// Related Topics 数组 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {


public:

    int ErFen(vector<int> nums,int target,int left,int right){
        if(left >= right){
            return left;
        }

        int mid = (right + left) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] > target){
            return ErFen(nums,target,left,mid - 1);
        }else{
            return  ErFen(nums,target,mid + 1,right);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int tmp = ErFen(nums,target,0,nums.size() - 1);
        if(target > nums[tmp]) tmp ++;
        return tmp;
    }
    /*
     * 解答成功:
			执行耗时:4 ms,击败了95.93% 的C++用户
			内存消耗:8.4 MB,击败了100.00% 的C++用户
     */
};
//leetcode submit region end(Prohibit modification and deletion)
