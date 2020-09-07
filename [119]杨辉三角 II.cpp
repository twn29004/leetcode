//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 3
//输出: [1,3,3,1]
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(k) 空间复杂度吗？ 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> V1(1,1);
        vector<int> V2(2,1);
        if(rowIndex == 0){
            return V1;
        }
        if(rowIndex == 1){
            return V2;
        }
        V1 = V2;
        V2.clear();
        for(int i = 2;i <= rowIndex;i ++){
            V2.push_back(1);
            for(int j = 0;j <V1.size() - 1;j ++){
                V2.push_back(V1[j] + V1[j + 1]);
            }
            V2.push_back(1);
            V1 = V2;
            V2.clear();
        }
        return V1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
