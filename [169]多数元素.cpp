//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [3,2,3]
//输出: 3 
//
// 示例 2: 
//
// 输入: [2,2,1,1,1,2,2]
//输出: 2
// 
// Related Topics 位运算 数组 分治算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        if(nums.size() == 0) return 0;
        map<int,int> M;
        for(int i = 0;i < nums.size();i ++){
            M[nums[i]] ++;
        }
        map<int,int>::iterator iter;
        int res;
        int Max = 0;
        for(iter = M.begin();iter != M.end();iter ++){
            if(iter->second > Max){
                Max = iter->second;
                res = iter->first;
            }
        }
        return  res;
         该方法的复杂度为O(n*log(n)),原因是Map的每次插入都需要耗费log(n)的世界         */
        //当然也可以用排序的方法，由于数目大于[n/2]所以这个众数也一定是中位数
        /*
        sort(nums.begin(),nums.end());  //为什么这个排序复杂度这么大
        return nums[(nums.size() - 1) / 2];
         */
        //下面是一个在官网看到的O(n)的解法

    }
};
//leetcode submit region end(Prohibit modification and deletion)
