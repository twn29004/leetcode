//给定一个二维网格和一个单词，找出该单词是否存在于网格中。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例: 
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false 
//
// 
//
// 提示： 
//
// 
// board 和 word 中只包含大写和小写英文字母。 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 1 <= word.length <= 10^3 
// 
// Related Topics 数组 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> isUsed;
    int m = 0,n = 0;

public:

    bool Judge(int i,int j){
        if(i >= m || i < 0 || j >= n || j < 0){
            return false;
        }
        return true;
    }

    bool BackTrack(vector<vector<char>> board,string word,int hang,int lie,int index){
        if(index >= word.length()){
            return true;
        }
        int tmp_hang;
        int tmp_lie;
        for(int i = 0;i < 4;i ++){
            tmp_hang = hang + dir[i][0];
            tmp_lie = lie + dir[i][1];
            if(Judge(tmp_hang,tmp_lie) && word[index] == board[tmp_hang][tmp_lie] && !isUsed[tmp_hang][tmp_lie]){
                isUsed[tmp_hang][tmp_lie] = true;
                bool tmp = BackTrack(board,word,tmp_hang,tmp_lie,index + 1);
                if(tmp){
                    return true;
                }else{
                    isUsed[tmp_hang][tmp_lie] = false;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        if(m != 0){
            n = board[0].size();
        }
        if(m == 0 || n == 0 || word.length() == 0){
            return false;
        }
        // 初始化
        for(int i = 0;i < m;i ++){
            vector<bool> tmp;
            for(int j = 0;j < n;j ++){
                tmp.push_back(false);
            }
            isUsed.push_back(tmp);
        }



        for(int i = 0;i < board.size();i ++){
            for(int j = 0;j < board[0].size();j ++){
                if(board[i][j] == word[0]){
                    isUsed[i][j] = true;
                    bool tmp = BackTrack(board,word,i,j,1);
                    if(tmp){
                        return true;
                    }else{
                        isUsed[i][j] = false;
                    }
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
