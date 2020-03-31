//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 50000 
// -50000 <= nums[i] <= 50000 
// 
//


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


   //快速排序
    void  QuickSort(vector<int>& arr,int start,int end){
        if(start >= end) return;
        int t_start = start;
        int t_end = end;
        while(start < end){
            while(end > start && arr[end] > arr[t_start]) end --;
            while(start < end && arr[start] <= arr[t_start]) start ++;
            swap(arr[start],arr[end]);
        }
        swap(arr[t_start],arr[end]);
        QuickSort(arr,t_start,end - 1);
        QuickSort(arr,end + 1,t_end);
    }

    //归并排序
    void MergeSort(vector<int>& arr,vector<int>& tmp,int begin,int end){
        if(begin >= end) return;  //>=的原因是后面的mid+1是有可能出现大于的情况的
        //分割
        int mid = (begin + end) / 2;
        MergeSort(arr,tmp,begin,mid);
        MergeSort(arr,tmp,mid+1,end);
        //合并
        int i = begin,j = mid + 1;  //分组1的开始和分组2的开始
        int count = begin;
        while(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                tmp[count] = arr[i];
                count ++;
                i ++;
            }else{
                tmp[count] = arr[j];
                count ++;
                j ++;
            }
        }
        while (i <= mid){
            tmp[count] = arr[i];
            i ++;
            count ++;
        }
        while (j <= end){
            tmp[count] = arr[j];
            j ++;
            count ++;
        }
        //arr = tmp;这句有问题，归还的莺应该只是受影响的部分
        for(int i = begin;i <= end;i ++){
            arr[i] = tmp[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        //这里采用快排的方法
        if(nums.size() == 0) return nums;
       // QuickSort(nums,0,nums.size() - 1);
       const int len = nums.size();
        vector<int> tmp(len);   //用于临时存放排序的数组
        MergeSort(nums,tmp,0,(int)nums.size() - 1);
        return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
