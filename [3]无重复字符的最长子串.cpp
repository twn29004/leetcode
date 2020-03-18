//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window


//leetcode submit region begin(Prohibit modification and deletion)

//AC


class Solution {
public:   //使用滑动窗口的方法
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        map<char,int> m;
        for(int i = 0;i < s.length();i ++){   //用于查询字母表
            m[s[i]] = 0;
        }

        int start = 0,end = -1;   //滑动窗口的起始和结束
        for(int i = 0;i < s.length();i ++){
            if(m[s[i]] != 1){   //说明在前面的子串中还没有出现过
                m[s[i]] = 1;
                end ++;
            }
            else{  //如果在前面出现过了
                max_len = max(max_len,end - start + 1);
                end ++;
                for(int j = start;j < end;j ++){
                    if(s[j] != s[end]){
                        m[s[j]] = 0;     //将之前字串中的一些字母移除
                    }
                    else{             //如果相等的话,将start放在他的后面一个
                        start = j + 1;
                        break;
                    }
                }
            }
        }
        max_len = max(max_len,end - start + 1);   //如果出现全部没有重复的话

        return max_len;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
