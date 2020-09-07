//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int cnt = 0;
    vector<int> copy;
    vector<int> nums;
public:
    // 可以采用分治的方法来解决，类似于归并排序
    void MergeSort(int left,int right){
        if(left >= right){
            return;
        }
        // 划分
        int mid = (left + right) / 2;
        MergeSort(left,mid);
        MergeSort(mid + 1,right);

        //然后开始合并

        int i = left,j = mid + 1;
        while(i <= mid && j <= right){  //如果左边的数大于右边的数，则cnt ++
            if(nums[i] > nums[j]){
                cnt += (mid - i + 1);
                copy.push_back(nums[j ++]);
            }else{
                copy.push_back(nums[i ++]);
            }
        }

        while(i <= mid){
            copy.push_back(nums[i ++]);
        }

        while (j <= right){
            copy.push_back(nums[j ++]);
        }
        //拷贝数组
        for(int i = left;i <= right;i ++){
            nums[i] = copy[i - left];
        }
        copy.clear();
        return;
    }
    int reversePairs(vector<int>& n) {
        if(n.size() <= 1){
            return 0;
        }
        nums = n;
        MergeSort(0,nums.size() - 1);
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
