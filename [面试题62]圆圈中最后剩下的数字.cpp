//0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。 
//
// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。 
//
// 
//
// 示例 1： 
//
// 输入: n = 5, m = 3
//输出: 3
// 
//
// 示例 2： 
//
// 输入: n = 10, m = 17
//输出: 2
// 
//
// 
//
// 限制： 
//
// 
// 1 <= n <= 10^5 
// 1 <= m <= 10^6 
// 
//


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
        if(m > n) m %= n;
        queue<int> Q;
        for(int i = 0;i < n;i ++){
            Q.push(i);
        }
        while(Q.size() != 1){
            for(int i = 1;i < m;i ++){
                int tmp = Q.front();
                Q.pop();
                Q.push(tmp);
            }
            Q.pop();
        }
        return Q.front();
        */
        int p=0;   //p代表的是F(n,m)的值，n表示总人数，这里初始化为0是F(1,m)的解
        for(int i=2;i<=n;i++)
        {
            p=(p+m)%i;  //这里代表的是F(i,m)的解
        }
        return p;
        //该算法的复杂度为O(n)
        //参考链接
        // https://blog.csdn.net/u011500062/article/details/72855826?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
        /*关于参考连接的理解
         * 首先可以F(1,3)一个人的时候，胜者肯定是1，所以F(1,3) = 0
         * F(2,3)两个人的时候，（F(1,3) + 3）% 2 = 1.
         * 显然后着的结果是与前者有关的。那么是什么关系呢。我觉得可以这样理解。
         * 比如说知道了F(10,3) = 3,那么怎么算F(11,3)呢。我觉得可以这样想11和10相差一个人。那就相当于11淘汰一个人之后。
         * 淘汰了后面的那个人又作为了新的开始。此时就转化为了F(10,3)的问题，不过区别就是其实往后移了3.因为F(10,3)的开始
         * 是0，而F(11,3)淘汰一个人转化成的F(10,3)问题的起点是从3开始的。相当于整体往后移了3的位置
         *
         * 于是就有了如下的解法
         * 当有n个人的时候，第m个淘汰。
         * F(n,m) = F(n - 1,m) + m
         *
         * 当是这存在一个问题就是m可能是大于当前的人数。因此要取模来处理一下。
         *
         *
         * 核心就是淘汰掉一个人之后就转化为了人数较少的问题。然后不断的递归或者说迭代便可以求出解
    }
};
//leetcode submit region end(Prohibit modification and deletion)
