//给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。 
//
// 如果不存在最后一个单词，请返回 0 。 
//
// 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。 
//
// 
//
// 示例: 
//
// 输入: "Hello World"
//输出: 5
// 
// Related Topics 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        string tmp = " ";
        tmp += s;
        s = tmp + " ";
        int res = 0;

        for(int i = 1;i < s.length() - 1;i ++,len ++){
            if(s[i] != ' ' && s[i - 1] == ' '){
                len = 1;
            }
            if(s[i] != ' ' && s[i + 1] == ' '){
                res = len;
            }
        }

        return res;

        /*
         * 11:34	info
			解答成功:
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:7 MB,击败了100.00% 的C++用户
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
