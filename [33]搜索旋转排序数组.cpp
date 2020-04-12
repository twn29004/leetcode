//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 
//
// 你可以假设数组中不存在重复的元素。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 示例 1: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
// 
//
// 示例 2: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1 
// Related Topics 数组 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
/*
    int BinarySearch(vector<int> nums,int target,int left,int right){
        if(left >= right){
            if(nums[left] == target){
                return left;
            }
            else{
                return -1;
            }
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return mid;
        }
        int res1 = BinarySearch(nums,target,left,mid - 1);
        if(res1 == -1){
            return BinarySearch(nums,target,mid + 1,right);
        }else{
            return res1;
        }
    }
*/
// tuoshi
    int BinarySearch(vector<int>nums,int target,int left,int right){
        if(left >= right){
            if(nums[left] == target){
                return left;
            }
            else{
                return -1;
            }
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return  mid;
        }
        if(nums[left] < nums[mid]){      // 左边是升序的
            if(target >= nums[left] && target < nums[mid]){   // 搜索的目标在左边范围内
                return BinarySearch(nums,target,left,mid - 1);
            }else{                                            // 搜索目标在左边范围
                return BinarySearch(nums,target,mid + 1,right);
            }
        }else{                            //
            if(target >= nums[mid] && target < nums[right]){//在右边范围内
                return BinarySearch(nums,target,mid + 1,right);
            }else{//只能从左边找
                return BinarySearch(nums,target,left,mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        int res = BinarySearch(nums,target,0,nums.size() - 1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
