//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 注意空字符串可被认为是有效字符串。 
//
// 示例 1: 
//
// 输入: "()"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "()[]{}"
//输出: true
// 
//
// 示例 3: 
//
// 输入: "(]"
//输出: false
// 
//
// 示例 4: 
//
// 输入: "([)]"
//输出: false
// 
//
// 示例 5: 
//
// 输入: "{[]}"
//输出: true 
// Related Topics 栈 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        //给每种括号给个类型，然后就是简答
        map<char,int> M;
        M['('] = 1; M[')'] = 1;
        M['{'] = 2; M['}'] = 2;
        M['['] = 3; M[']'] = 3;
        stack<int> S;
        int i;
        for(i = 0;i < s.length();i ++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                S.push(M[s[i]]);
            }else{
                if(S.empty() || S.top() != M[s[i]]){
                    break;
                }else{
                    S.pop();
                }
            }
        }

        return (i >= s.length() && S.empty()) ? true : false;


        /*
         * 14:48	info
			解答成功:
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:6.7 MB,击败了100.00% 的C++用户
         */
    }
};
//leetcode submit region end(Prohibit modification and deletion)
