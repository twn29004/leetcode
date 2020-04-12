class Solution {
public:

    // 先给数组排个序.遍历数组。对于每一个数。选择nums[i].如果nums[i] > 0结束循环。否则，令left = i + 1,r = n - 1
    /*
     * 如果和大于0，说明right他打了，左移
     * 如果和小于0，说明left太小了，右移
     * 如果等于0，得到一个结果。同时判断left的下一个和right的下一个是否重复。重复的找到第一个不相同的，继续求
     * */

    vector<int> Aggre(int x,int y,int z){
        vector<int> V;
        V.push_back(x);
        V.push_back(y);
        V.push_back(z);
        return V;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        int left,right;

        if(nums.size() <= 2 || nums[0] > 0 || nums[len - 1] < 0){
            return res;
        }

        for(int i = 0;i < len;i ++){
            if(nums[i] > 0){
                return res;
            }

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;     // 已经求过这个数的解了，避免重复解
            }

            left = i + 1;
            right  = len - 1;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    res.push_back(Aggre(nums[i],nums[left],nums[right]));
                    while(left < right && nums[left] == nums[left + 1]){
                        left ++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right --;
                    }
                }
                if(nums[i] + nums[left] + nums[right] > 0){
                    right --;
                }else{
                    left ++;
                }
            }
        }
        return res;
         */
        /*
         * 16:05	info
			解答成功:
			执行耗时:144 ms,击败了18.95% 的C++用户
			内存消耗:14.9 MB,击败了39.16% 的C++用户
         */


    }
};