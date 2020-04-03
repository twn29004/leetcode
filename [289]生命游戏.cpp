//根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。 
//
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dea
//d）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律： 
//
// 
// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；      意思就是周围只有一个活细胞就会死亡
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；   有两个或三个活细胞能够存活
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；        超过三个活细胞死亡
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；              正好有三个的话，死细胞能复活
// 
//
// 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生
//和死亡是同时发生的。 
//
// 
//
// 示例： 
//
// 输入： 
//[
//  [0,1,0],
//  [0,0,1],
//  [1,1,1],
//  [0,0,0]
//]
//输出：
//[
//  [0,0,0],
//  [1,0,1],
//  [0,1,1],
//  [0,1,0]
//] 
//
// 
//
// 进阶： 
//
// 
// 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。 
// 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？ 
// 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool Judge(int i,int j,int m,int n){
        if(i >= 0 && i < m && j >= 0 && j < n){
            return true;
        }else{
            return false;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
        int m = board.size();
        int n = board[0].size();
        //vector<vector<int>> res;    //用于存放结果
/*
        for(int i = 0;i < m;i ++){     //初始化res，全部为0
            vector<int> tmp;
            for(int j = 0;j < n;j ++){
                tmp.push_back(0);
            }
            res.push_back(tmp);
        }
        int cnt = 0;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                //不如先计算周围活细胞的数量
                cnt = 0;
                for(int k = 0;k < 8;k ++){
                    if(Judge(i + dir[k][0], j + dir[k][1],m,n)){
                        cnt += board[i+dir[k][0]][j+dir[k][1]];
                    }
                    if(cnt > 3){   //在继续算下去就没意思了
                        break;
                    }
                }

                if(board[i][j] == 0 && cnt == 3){     //死细胞复活
                    res[i][j] = 1;
                    continue;
                }

                if(board[i][j]){
                   if(cnt < 2 || cnt > 3){   //注意这里是小于2，不是 ==1，因为还有0要考虑
                       res[i][j] = 0;
                   }else{
                       res[i][j] = 1;
                       cout<<i<<" "<<j<<" "<<cnt<<endl;
                   }
                }

            }
        }
        board = res;
        */
        /*
         * 8:52	info
			解答成功:
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:7.3 MB,击败了100.00% 的C++用户
         * emmm,好像没有按题目要求。
         */

        //上述方法占用了大量的内存空间，我们可以考虑使用额外的状态来直接对原数组进行修改
        // 我们可以这样考虑，将复活细胞的状态变为2，将死掉的细胞的状态变为3.这样对2取余的话，还能得到他们原来的状态
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                int cnt = 0;
                for(int k = 0;k < 8;k ++){
                    if(Judge(i + dir[k][0],j + dir[k][1],m,n)){
                        cnt += (board[i+dir[k][0]][j+dir[k][1]] % 2);
                    }
                    if(cnt > 3){
                        break;
                    }
                }

                if(board[i][j] == 0 && cnt == 3){     //死细胞复活
                    board[i][j] = 2;
                    continue;
                }

                if(board[i][j]){
                    if(cnt < 2 || cnt > 3){   //注意这里是小于2，不是 ==1，因为还有0要考虑
                        board[i][j] = 3;
                    }else{
                        board[i][j] = 1;
                    }
                }
            }
        }

        //根据额外的状态来调整细胞的新状态
        for(int i = 0;i < m;i ++){
            for(int  j = 0;j < n;j ++){
             if(board[i][j] == 2){  //这个是死细胞复活的状态
                 board[i][j] = 1;
             }
             if(board[i][j] == 3){  //这是活细胞死了的状态
                 board[i][j] = 0;
             }
            }
        }

        /*
         * info
			解答成功:
			执行耗时:4 ms,击败了66.13% 的C++用户
			内存消耗:7.2 MB,击败了100.00% 的C++用户
         * 神奇的评测机
         */
    }

};
//leetcode submit region end(Prohibit modification and deletion)
