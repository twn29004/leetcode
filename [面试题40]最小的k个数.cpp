//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 堆 分治算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void QuickSort(vector<int>& arr,int k,int start,int end){
        int t_start = start;
        int t_end = end;
        while(start < end){
            while(start <= end && arr[start] < arr[0]) start ++;
            while(end >= start && arr[end] > arr[0]) end --;
            swap(arr[start],arr[end]);
        }
        swap(arr[0],arr[end]);
        int t_k = end - t_start + 1;
        if(t_k == k) return;
        if(t_k < k){   //说明结果在左边
            QuickSort(arr,k,t_start,end);
        }
        else{
            int t = end - 1;
            vector<int>::iterator iter = arr.brgin();
            while(t){
                iter ++;
            }
            arr = *iter;
            QuickSort(arr,t_k - k,end,t_end);
        }
        //然后求出现在的arr[0是这组数中第几大。
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        /*
        sort(arr.begin(),arr.end());
        vector<int> res;
        for(int i = 0;i < k;i ++){
            res.push_back(arr[i]);
        }
        return res;
         */
        //排序的方法可是使用快排的方法来解决这个问题。
        if(arr.size() == 0)return 0;
        QuickSort(arr,k,1,arr.size()-1);
        vector<int> res;
        for(int i = 0;i < k;i ++){
            res.push_back(arr[i]);
        }
        return  res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
