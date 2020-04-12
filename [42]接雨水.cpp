//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Mar
//cos 贡献此图。 
//
// 示例: 
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6 
// Related Topics 栈 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        //解法1：暴力法，对每个高度，求其能装的最大的体积，就是找到他作为坑底的最高的边界，该解法的复杂度为n^2
        /*
        int res = 0;
        int max_left,max_right;
        for(int i = 0;i < height.size();i ++){
            max_left = *max_element(height.begin(),height.begin() + i + 1);
            max_right = *max_element(height.begin() + i,height.end());
            res += (min(max_left,max_right) - height[i]);
        }
        return res;
         */
        //哦豁，这个暴力法T了，不知道是不是因为max_element()的问题，再改进一下

        //显然上述算法存在一个可以很好的改进的地方，我们没到一个新的i,都要重新计算max_left和max_right。我们完全可以把他先计算出来，保存好，然后再拿来用，这大噶就是拿空间换时间
        /*
        if(height.size() <= 2) return 0;

        vector<int> max_left(height.size()),max_right(height.size());
        max_left[0] = height[0];
        max_right[height.size() - 1] = height[height.size() - 1];
        int res = 0;

        for(int i = 1,j = height.size() - 2; i < height.size() && j >= 0; i ++,j --){
            max_left[i] = max(max_left[i - 1],height[i]);
            max_right[j] = max(max_right[j + 1],height[j]);
            cout<<i<<"  "<<j<<endl;
        }

        for(int i = 0;i < height.size();i ++){
            res += (min(max_left[i],max_right[i]) - height[i]);
        }

        return res;
         */
        /*
			解答成功:
			执行耗时:8 ms,击败了68.64% 的C++用户
			内存消耗:7 MB,击败了100.00% 的C++用户
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
