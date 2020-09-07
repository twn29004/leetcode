//给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。 
//
// 两个相邻元素间的距离为 1 。 
//
// 示例 1: 
//输入: 
//
// 
//0 0 0
//0 1 0
//0 0 0
// 
//
// 输出: 
//
// 
//0 0 0
//0 1 0
//0 0 0
// 
//
// 示例 2: 
//输入: 
//
// 
//0 0 0
//0 1 0
//1 1 1
// 
//
// 输出: 
//
// 
//0 0 0
//0 1 0
//1 2 1
// 
//
// 注意: 
//
// 
// 给定矩阵的元素个数不超过 10000。 
// 给定矩阵中至少有一个元素是 0。 
// 矩阵中的元素只在四个方向上相邻: 上、下、左、右。 
// 
// Related Topics 深度优先搜索 广度优先搜索


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;

public:

    bool Judge(int i,int j){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> V1;
        vector<vector<int>> V2;
        vector<int> tmp;

        m = matrix.size();
        n = matrix[0].size();


        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(matrix[i][j] == 0){
                    tmp.push_back(i);
                    tmp.push_back(j);
                    V1.push_back(tmp);
                    tmp.clear();
                }else{
                    matrix[i][j] = -1;
                }
            }
        }

        int deep = 1;
        while(!V1.empty()){
            for(int i = 0;i < V1.size();i ++){
                for(int k = 0;k < 4;k ++){
                    int i_tmp = V1[i][0] + dir[k][0];
                    int j_tmp = V1[i][1] + dir[k][1];
                    if(Judge(i_tmp,j_tmp) && matrix[i_tmp][j_tmp] == -1){
                        matrix[i_tmp][j_tmp] = deep;
                        tmp.clear();
                        tmp.push_back(i_tmp);
                        tmp.push_back(j_tmp);
                        V2.push_back(tmp);
                    }
                }
            }
            V1 = V2;
            deep ++;
            V2.clear();
        }

        return matrix;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
