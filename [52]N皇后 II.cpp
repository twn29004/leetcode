//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回 n 皇后不同的解决方案的数量。 
//
// 示例: 
//
// 输入: 4
//输出: 2
//解释: 4 皇后问题存在如下两个不同的解法。
//[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
// 
// Related Topics 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<bool> vis[3];  //↖↑↗三个方向
    int N;
    int sum = 0;

public:

    void DFS(int row,int n)
    {
        int i;
        if(row == n + 1)//已经够n行了
        {
            sum ++;
            return ;
        }
        for(i = 1; i <= n; i++)
        {
            if(vis[0][row-i+n] == 0 && vis[1][i] == 0 && vis[2][row+i] == 0)
            {//不会回溯的同学要好好看看学习学习
                vis[0][row-i+n] = vis[1][i] = vis[2][row+i] = 1;//变值
                DFS(row + 1,n);//深搜
                vis[0][row-i+n] = vis[1][i] = vis[2][row+i] = 0;//回溯
            }
        }
    }


    int totalNQueens(int n) {
        // 左上的行和列的差值相等。当时由于出现了负数，所以要整体加N，这样的话，会有n + n - 1个
        for(int i = 0;i < 3 * n; i ++){
            vis[0].push_back(false);
            vis[1].push_back(false);
            vis[2].push_back(false);
        }
        N = n;
        DFS(1,n);
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
