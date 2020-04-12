//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> V;
    int m;

public:

    void BackTrack(int index,int k){
        if(index >= V.size()){
            m ++;
            return;
        }
        for(int i = index;i < V.size();i ++){
            swap(V[i],V[index]);
            BackTrack(index + 1,k);
            if(k == m){
                return;
            }
            swap(V[i],V[index]);
        }
    }

    string getPermutation(int n, int k) {


        if(k == 0){
            return "";
        }

        for(int i = 1;i <= n;i ++){
            V.push_back(i);
        }


       BackTrack(0,k - 1);

       string res;

        for(int i = 0;i < V.size();i ++){
            stringstream stream;
            stream << V[i];
            res += stream.str();
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
