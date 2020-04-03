//实现 strStr() 函数。 
//
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
//果不存在，则返回 -1。 
//
// 示例 1: 
//
// 输入: haystack = "hello", needle = "ll"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: haystack = "aaaaa", needle = "bba"
//输出: -1
// 
//
// 说明: 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 
// Related Topics 双指针 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    //首先我们需要计算一个fail数组
    void MakeFail(vector<int>& Fail,string mod){   //fail数组的计算之和mod有关
        int i = 1,j = 0;   //注意这里的i为遍历的下标，j为代表的是前面的最长公共前后缀的大小
        Fail[0] = 0;
        for(;i < mod.length();i ++){
            while(j > 0 && mod[i] != mod[j]){
                j = Fail[j - 1];
            }
            if(mod[i] == mod[j]){
                Fail[i] = ++j;
            }
            else{
                Fail[i] = 0;
            }
        }
    }

    int strStr(string haystack, string needle) {

        /*
         * 几个特殊情况:
         * 1. haystack为空
         * 2. needle为空
         * */

        if(haystack.length() == 0 && needle.length() == 0) return 0;   //对于的情况就是两个都为空
        if(haystack.length() == 0 && needle.length() != 0) return -1;
        if(needle.length() == 0) return 0;
/*
        int n = needle.length();
        int h = haystack.length();
        int i;
        for(i = 0;i < h;i ++){
            if(haystack[i] == needle[0]){   //有第一个相等
                int j = 0;
                int tmp = i;
               while (haystack[tmp] == needle[j] && tmp < h && j < n){
                   tmp ++;
                   j ++;
               }
               if(j == n) break;
            }
        }
        return i < h ? i : -1;
*/
        //上述方法T了
        //下面使用KMP算法
        //https://blog.jm233333.com/page/35/
        //参考刘神博客



        const int mod_len = needle.length();
        vector<int> fail(mod_len);
        MakeFail(fail,needle);
        //得到fail数组后开始匹配
        int i = 0,j = 0;
        for(;i < haystack.length() && j < needle.length();i ++){
            if(haystack[i] == needle[j]){   //匹配成功接着向后移动
                j ++;
            }else{
                if(j > 0){
                    j = fail[j - 1];
                    i --;
                }
                else{
                    j = 0;
                }
            }
        }

        if(j >= needle.length()){
            return i - j;
        }else{
            return -1;
        }

    }


    /*
     * 	解答成功:
			执行耗时:4 ms,击败了91.46% 的C++用户
			内存消耗:7.4 MB,击败了100.00% 的C++用户
     *  KMP还是强
     */
};
//leetcode submit region end(Prohibit modification and deletion)
