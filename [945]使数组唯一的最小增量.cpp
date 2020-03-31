//给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。 
//
// 返回使 A 中的每个值都是唯一的最少操作次数。 
//
// 示例 1: 
//
// 输入：[1,2,2]
//输出：1
//解释：经过一次 move 操作，数组将变为 [1, 2, 3]。 
//
// 示例 2: 
//
// 输入：[3,2,1,2,1,7]
//输出：6
//解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
//可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
// 
//
// 提示： 
//
// 
// 0 <= A.length <= 40000 
// 0 <= A[i] < 40000 
// 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        /*
        int res  = 0;            //这题目有问题啊
        sort(A.begin(),A.end());   //sort一般默认为升序排列
        const int len = 45000;    //注意这里的大小并不是40000,因为这个为了避免重复很可能会超过40000
        bool B[len] = {0};
        for(int i = 0;i < A.size();i ++){
            if(B[A[i]] == 0) B[A[i]] = 1;
        }
        for(int i = 1;i < A.size();i ++){
            if(A[i] == A[i - 1]){  //至少存在一个相等
                int tmp = A[i];
                while(B[tmp]) tmp++;  //找到最近的一个位置放进去
                B[tmp] = 1;
                res += (tmp - A[i]);
            }
        }
        return  res;
         */
        /*上面这个的复杂度太窒息了
         */
        /*
        vector<int> B(45000);
        int res = 0;
        for(int i = 0;i < A.size();i ++){
            if(B[A[i]] == 0) B[A[i]] = 1;
        }
        for(int i = 0;i < A.size();i ++){
            if(B[A[i]] == 1){
                B[A[i]] ++;  //B[A[i]] = 2表示第一次出现
                continue;
            }
            if(B[A[i]] == 2){ //说明前面已经出现过了
                int tmp = A[i];
                while(B[tmp] != 0){
                    tmp ++;  //=1,=2都不行
                }
                B[tmp] = 2;
                res += (tmp - A[i]);
            }
        }
        return res;
         */
        /*上面两个方法的复杂度都是n^2,裂开了,不太行,看看题解
         */
        //下面是一个n*log(n)的算法
        sort(A.begin(),A.end());
        int res = 0;
        for(int i = 1;i < A.size();i ++){
            if(A[i] <= A[i - 1]){
                res += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
