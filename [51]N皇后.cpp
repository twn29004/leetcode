//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。 
//
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 示例: 
//
// 输入: 4
//输出: [
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
//解释: 4 皇后问题存在两个不同的解法。
// 
// Related Topics 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<string>> res;
    vector<bool> vis[3];
    int N;

public:

    string Change(int index){
        string str;
        for(int i = 0;i < N;i ++){
            if(i == index){
                str += "Q";
            }else{
                str += ".";
            }
        }
        return str;
    }

    void DFS(int row,vector<string>& tmp){
        if(row >= N){
            res.push_back(tmp);
            return;
        }
        for(int i = 0;i < N;i ++){
            if(!vis[0][row - i + N] && !vis[1][i] && !vis[2][i + row]){
                vis[0][row - i + N] = vis[1][i] = vis[2][i + row] = true;

                string t = Change(i);
                tmp.push_back(t);

                DFS(row + 1,tmp);

                tmp.erase(tmp.end() - 1);

                vis[0][row - i + N] = vis[1][i] = vis[2][i + row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // 初始化
        N = n;
        for(int i = 0;i < 2 * n + 5;i ++){
            vis[0].push_back(false);
            vis[1].push_back(false);
            vis[2].push_back(false);
        }
        vector<string> tmp;
        DFS(0,tmp);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
