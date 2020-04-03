//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。 
//
// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。 
//
// 你可以假设 nums1 和 nums2 不会同时为空。 
//
// 示例 1: 
//
// nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
// 
//
// 示例 2: 
//
// nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5
// 
// Related Topics 数组 二分查找 分治算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() + nums2.size() == 0) return 0;

        vector<int> V;
        int len = (nums1.size() + nums2.size()) / 2;
        cout<<"error"<<endl;
        cout<<nums1.size()<<"1"<<endl;
        cout<<nums2.size()<<"2"<<endl;
        int count = 0;
        int i = 0,j = 0;
        while(count  <= len && i < nums1.size() && j < nums2.size()){
               if(nums1[i] < nums2[j]){
                   V.push_back(nums1[i]);
                   i ++;
               }else{
                   V.push_back(nums2[j]);
                   j++;
               }
               count ++;
        }

        /*
         * 傻逼了，把这段忘了
         */
        while(i < nums1.size()){
            V.push_back(nums1[i]);
            i ++;
        }
        while(j < nums2.size()){
            V.push_back(nums2[j]);
            j ++;
        }

        if((nums1.size() + nums2.size()) % 2 == 0){
            return ((double)V[len] + (double)V[len - 1]) / 2;
        }else{
            return V[len];
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
