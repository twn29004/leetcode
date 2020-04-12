//给出一个区间的集合，请合并所有重叠的区间。 
//
// 示例 1: 
//
// 输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2: 
//
// 输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
// Related Topics 排序 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int Judge(int left,int right,vector<int> num1){
        if(right < num1[0]){
            return 1;
        }
        if(right >= num1[0] && right < num1[1]){
            return 2;
        }
        if(right >= num1[1]){
            return 3;
        }
        return 0;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;

        if(intervals.size() == 0 || intervals[0].size() == 0){
            return res;
        }

        vector<int> tmp;
        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i = 1;i < intervals.size();i ++){
            switch (Judge(left,right,intervals[i])){
                case 1:
                    tmp.clear();
                    tmp.push_back(left);
                    tmp.push_back(right);
                    res.push_back(tmp);
                    left = intervals[i][0];
                    right = intervals[i][1];
                    break;
                case 2:
                    right = intervals[i][1];
                    break;
                case 3:
                    break;
            }
        }

        tmp.clear();
        tmp.push_back(left);
        tmp.push_back(right);
        res.push_back(tmp);

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
