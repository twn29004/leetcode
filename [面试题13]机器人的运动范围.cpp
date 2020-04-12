//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
//格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
//它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 1： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
//


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int Add(int x,int y){
        int res = 0;
        while(x){
            res += (x % 10);
            x /= 10;
        }
        while(y){
            res += (y % 10);
            y /= 10;
        }
        return res;
    }

    bool Judge(int x,int y,int m,int n){
        if(x < 0 || x >= m || y < 0 || y >= n){
            return false;
        }else{
            return true;
        }
    }


    void dfs(int i,int j,int& res,int k,int m,int n,vector<vector<bool>>& M){
        if(Judge(i,j,m,n) && Add(i,j) <= k && !M[i][j]){  // 这里的意思是，如果位置合法且没有访问过，则继续搜索，否则就返回了
            res ++;
            M[i][j] = true;
        }else{
            return;
        }
        for(int h = 0;h < 4;h ++){
            int i_tmp = i + dir[h][0];
            int j_tmp = j + dir[h][1];
            dfs(i_tmp,j_tmp,res,k,m,n,M);
        }
    }

    int movingCount(int m, int n, int k) {

        int res = 0;
        vector<vector<bool>> M;
        for(int i = 0;i < m;i ++){
            vector<bool> tmp;
            for(int j = 0;j < n;j ++){
                tmp.push_back(false);
            }
            M.push_back(tmp);
        }
        dfs(0,0,res,k,m,n,M);
        return res;

        /*
        // 初始化
        for(int i = 0;i < m;i ++){
            vector<int> tmp;
            for(int j = 0;j < n;j ++){
               tmp.push_back(i * n + j);
            }
            M.push_back(tmp);
        }

        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(Add(i,j) <= k){
                    for(int h = 0;h < 2;h ++){
                        int i_tmp = i + dir[h][0];
                        int j_tmp = j + dir[h][1];
                        if(Judge(i_tmp,j_tmp,m,n) && Add(i_tmp,j_tmp) <= k){
                            M[i][j] = min(M[i][j],M[i_tmp][j_tmp]);
                            M[i_tmp][j_tmp] = M[i][j];
                        }
                    }
                }
            }
        }

        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(M[i][j] == 0){
                    cnt ++;
                    cout<<"["<<i<<","<<j<<"]"<<" ";
                }else{
                    cout<<"("<<i<<","<<j<<")"<<" ";
                }
            }
            cout<<endl;
        }

        return cnt;
         */
        // 上述方法应该可以算作暴力法
        /**
         * 9:47	info
			解答成功:
			执行耗时:16 ms,击败了10.36% 的C++用户
			内存消耗:7.8 MB,击败了100.00% 的C++用户
         */

        // 出现耗时这么长的原因是因为搜索过程中伴随着大量的重复。应该想办法去掉这些重复。每个结点只搜索一次。
        // 这种题应该可以使用深度优先搜索来完成
        /*
         * 14:47	info
			解答成功:
			执行耗时:4 ms,击败了81.25% 的C++用户
			内存消耗:7.2 MB,击败了100.00% 的C++用户
            深搜这个还是很快的
         */

    }
};
//leetcode submit region end(Prohibit modification and deletion)
