//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> res;
public:

    void BackTrack(int n,int k,int index,vector<int> tmp){
        if(k == 0){
            res.push_back(tmp);
            return;
        }
        for(int i = index;i <= n;i ++){
            tmp.push_back(i);
            BackTrack(n,k - 1,i + 1,tmp);
            tmp.erase(tmp.end() - 1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        BackTrack(n,k,1,tmp);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
