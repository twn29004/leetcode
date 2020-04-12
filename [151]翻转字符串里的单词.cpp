//给定一个字符串，逐个翻转字符串中的每个单词。 
//
// 
//
// 示例 1： 
//
// 输入: "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 输入: "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入: "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 说明： 
//
// 
// 无空格字符构成一个单词。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 
//
// 进阶： 
//
// 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。 
// Related Topics 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
        stack<string> S;
        int len = 0;
        int start;

        //下面解释识别每个单词，然后入栈
        string tmp = " ";
        tmp += s;
        s = tmp + " ";    // 在s的前后加上空格方便处理
        for(int i = 1;i < s.length() - 1;i ++,len ++){
            if(s[i] != ' ' && s[i - 1] == ' '){
                start = i;
                len = 1;
            }
            if(s[i] != ' ' && s[i + 1] == ' '){
                S.push(s.substr(start,len));
            }
        }


        tmp = "";
        if(S.size() == 0){
            return tmp;
        }

        while(S.size() != 1){
            tmp += (S.top() + " ");
            S.pop();
        }
        tmp += S.top();
        return tmp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
