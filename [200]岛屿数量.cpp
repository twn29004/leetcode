//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 示例 1: 
//
// 输入:
//11110
//11010
//11000
//00000
//输出: 1
// 
//
// 示例 2: 
//
// 输入:
//11000
//11000
//00100
//00011
//输出: 3
//解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集


//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {

    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    int hang,lie;
    vector<int> pre;

public:

    // 找到他的祖先
    int unionsearch(int& root){
        int son = root;
        while(root != pre[root] && pre[root] != -1){
            root = pre[root];
        }
        // 路径压缩
        while(son != pre[son] && pre[son] != -1){
            int tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        return root;
    }

    // 合并
    void join(int root1,int root2){
        int x = unionsearch(root1);
        int y = unionsearch(root2);
        if(x != y){
            pre[x] = y;
        }
    }

    bool judge(int x,int y){
        if(x < 0 || x >= hang || y < 0 || y >= lie){
            return false;
        }else{
            return true;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // 使用并查集来解决该问题
        // 使用pre数组来存储每个位置的祖先。每个位置可以计算为i * n + j
        hang = grid.size();
        if(hang != 0){
            lie = grid[0].size();
            if(lie == 0){
                return 0;
            }
        }else{
            return 0;
        }


        // 初始化
       for(int i = 0;i < hang;i ++){
           for(int j = 0;j < lie;j ++){
               if(grid[i][j] == '1'){
                   pre.push_back(i * lie + j);
               }else{
                   pre.push_back(-1);
               }
           }
       }

        // 合并
        for(int i = 0;i < hang;i ++){
            for(int j = 0;j < lie;j ++){
                if(grid[i][j] == '1'){
                    for(int  k = 0;k < 4;k ++){
                        int tmp_x = i + dir[k][0];
                        int tmp_y = j + dir[k][1];
                        if(judge(tmp_x,tmp_y) && grid[tmp_x][tmp_y] == '1'){
                            int t1 = i * lie + j;
                            int t2 = tmp_x * lie + tmp_y;
                            join(t1,t2);
                        }
                    }
                }
            }
        }

        // 再来搜素有几个
        int res = 0;
        for(int i = 0;i < pre.size();i ++){
            if(pre[i] == i){
                res ++;
            }
        }

        return res;
    }
};
 */
class Solution {
    int hang,lie;
    int res;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

public:

    bool judge(int x,int y){
        if(x < 0 || x >= hang || y < 0 || y >= lie){
            return false;
        }
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        hang = grid.size();
        if(hang == 0)
            return 0;
        lie = grid[0].size();
        if(lie == 0)
            return  0;

        //使用BFS的解法
        vector<int> V1;
        vector<int> V2;
        for(int i = 0;i < hang;i ++){
            for(int j = 0;j < lie;j ++){
                if(grid[i][j] == '1'){
                    V1.push_back(i * lie + j);
                    grid[i][j] = '0';
                    V2.clear();
                    while(!V1.empty()){
                        for(int k = 0;k < V1.size();k ++){

                            int x = V1[k] / lie;
                            int y = V1[k] - lie * x;

                            for(int h = 0;h < 4;h ++){
                                int tmp_x = x + dir[h][0];
                                int tmp_y = y + dir[h][1];
                                if(judge(tmp_x,tmp_y) && grid[tmp_x][tmp_y] == '1'){
                                    V2.push_back(tmp_x * lie + tmp_y);
                                    grid[tmp_x][tmp_y] = '0';
                                }
                            }
                        }

                        V1 = V2;
                        V2.clear();
                    }
                    res ++;
                }
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
