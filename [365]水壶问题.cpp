//有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？ 
//
// 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。 
//
// 你允许： 
//
// 
// 装满任意一个水壶 
// 清空任意一个水壶 
// 从一个水壶向另外一个水壶倒水，直到装满或者倒空 
// 
//
// 示例 1: (From the famous "Die Hard" example) 
//
// 输入: x = 3, y = 5, z = 4
//输出: True
// 
//
// 示例 2: 
//
// 输入: x = 2, y = 6, z = 5
//输出: False
// 
// Related Topics 数学


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //辗转相除法求最大公约数
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if(x==y&&y==0) return false;
        if(x==0&&y!=z) return false;
        if(y==0&&x!=z) return false;
        if(x+y<z) return false;
        return z%gcd(x,y)==0;
    }
    /*
     * 	解答成功:
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:5.9 MB,击败了100.00% 的C++用户
     * 这个代码太牛逼了
     * //参考链接：https://blog.csdn.net/ATFWUS/article/details/105006634
     */
};
//leetcode submit region end(Prohibit modification and deletion)
