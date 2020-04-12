//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 如果数组中不存在目标值，返回 [-1, -1]。 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4] 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1] 
// Related Topics 数组 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int Left(vector<int> nums,int target,int left,int right){
        if(right - left <= 1){
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;
            return -1;
        }

        int mid = (left + right) / 2;
        if(nums[mid] >= target){         //这样可以找最左边的
          return Left(nums,target,left,mid);
        }else{
            return Left(nums,target,mid + 1,right);
        }
    }

    int Right(vector<int> nums,int target,int left,int right){
        if(right - left <= 1){
            if(nums[right] == target) return right;
            if(nums[left] == target) return left;
            return -1;
        }

        int mid = (left + right) / 2;
        if(nums[mid] > target){         //这样可以找最右边的
            return Right(nums,target,left,mid - 1);
        }else{
            return Right(nums,target,mid,right);
        }
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {

        //由于是排好序的数组，显然使用的是二分查找。
        //首先找到target的一个值所在的位置
        int tmp,left,right;
        vector<int> res(2,-1);

        if(nums.size() == 0){
            return res;
        }
        /*
        tmp = ErFen(nums,target,0,nums.size()-1);
        if(tmp == -1){
            return res;
        }
        left = tmp;
        right = left;
        while(left >= 0 && nums[left] == target){
            left --;
        }
        left ++;
        while(right < nums.size() && nums[right] == target){
            right ++;
        }
        right --;
        res[0] = left;
        res[1] = right;
        return res;
        */
        //上述算法的复杂度并未达到log(n)，最坏的情况是O(n),看是否还可以改进一下。可以继续利用二分查找
        /*
         * info
			解答成功:
			执行耗时:4 ms,击败了98.78% 的C++用户
			内存消耗:9.2 MB,击败了100.00% 的C++用户
         */

        left = Left(nums,target,0,nums.size() - 1);
        if(left == -1){
            return res;
        }
        right = Right(nums,target,0,nums.size() - 1);
        //我傻了，两次二分的耗时比一次加遍历的还长，还多加了内存空间，当然left和right还是可以优化的，这里不再赘述
        res[0] = left;
        res[1] = right;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
