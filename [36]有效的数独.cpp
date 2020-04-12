//判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 
//
// 上图是一个部分填充的有效的数独。 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 示例 1: 
//
// 输入:
//[
//  ["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//[
//  ["8","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: false
//解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。 
//
// 说明: 
//
// 
// 一个有效的数独（部分已被填充）不一定是可解的。 
// 只需要根据以上规则，验证已经填入的数字是否有效即可。 
// 给定数独序列只包含数字 1-9 和字符 '.' 。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isExist[10];
        //先判断每行
        for(int i = 0;i < board.size();i ++){
            memset(isExist,false,10);   //全部初始化为false
            for(int j = 0;j < board[0].size();j ++){
                if(board[i][j] == '.'){
                    continue;
                }
                int tmp = board[i][j] - 48;
                if(isExist[tmp]){
                    cout<<1<<endl;
                    return false;
                }else{
                    isExist[tmp] = true;
                }
            }
        }

        //再判断每列
        for(int i = 0;i <  board[0].size();i ++){
            memset(isExist,false,10);   //全部初始化为false
            for(int j = 0;j < board.size();j ++){
                if(board[j][i] == '.'){
                    continue;
                }
                int tmp = board[j][i] - 48;
                if(isExist[tmp]){
                    cout<<2<<endl;
                    return false;
                }else{
                    isExist[tmp] = true;
                }
            }
        }

        //判断每个格子中的值
        for(int i = 0;i < board.size();i += 3){
            for(int j = 0;j < board[0].size();j += 3){
                memset(isExist,false,10);
                for(int k = i;k < i + 3;k ++){
                    for(int h = j;h < j + 3;h ++){
                        if(board[k][h] == '.'){
                            continue;
                        }
                        int tmp = board[k][h] - 48;
                        if(isExist[tmp]){
                            cout<<3<<endl;
                            return false;
                        }else{
                            isExist[tmp] = true;
                        }
                    }
                }
            }
        }
        return true;
        /*
         * 	info
			解答成功:
			执行耗时:20 ms,击败了47.43% 的C++用户
			内存消耗:7.1 MB,击败了100.00% 的C++用户
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
