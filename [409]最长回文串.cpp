//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。 
//
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。 
//
// 注意: 
//假设字符串的长度不会超过 1010。 
//
// 示例 1: 
//
// 
//输入:
//"abccccdd"
//
//输出:
//7
//
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
// 
// Related Topics 哈希表


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindrome(string s) {
       map<char,int> M;
       for(int i = 0;i < s.length();i ++){
           M[s[i]] ++;
       }
       //找出最大的奇数放在中间
       map<char,int>::iterator iter;
       int Max_j = 0;
       char t;    //记录这个最大奇数的下标
       for(iter = M.begin();iter != M.end();iter ++){
           if(iter->second % 2 != 0 && iter->second > Max_j){
               Max_j = iter->second;
               t = iter->first;
           }
       }
       M[t] = 0;
       int res = Max_j;
       for(iter = M.begin();iter != M.end();iter ++){
           if(iter ->second % 2 == 0){
               res += iter->second;
           }else{
               res += (iter->second - 1);
           }
       }
       return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
