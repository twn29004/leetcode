//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)

//n^2的解法,讨论双核的算法,就这已经击败了90%的用户,这评测机也太神奇了
class Solution {
public:
    string longestPalindrome(string s) {
        /*  复杂度为n^2的解法
        int start,end,max_len = 0;
        int res_start = 0;
        int tmp_len = 0;
        for(int index = 0;index < s.length();index ++){
            //字符串的长度为奇数的情况
            start = index; end = index;
            while(start >= 0 && end < s.length() && s[start] == s[end]){
                start --;
                end ++;
            }
            tmp_len = (end - start - 1);
            if(tmp_len > max_len){   //更新
                res_start = start + 1;
                max_len = tmp_len;
            }

            //字符串长度为偶数的情况
            start = index;
            end = index + 1;
            while(start >= 0 && end < s.length() && s[start] == s[end]){
                start --;
                end ++;
            }
            tmp_len = (end - start - 1);
            if(tmp_len > max_len){  //更新
                res_start = start + 1;
                max_len = tmp_len;
            }
        }
        // cout<<max_len<<endl<<endl;
        //cout<<s.length()<<endl;
        cout<<res_start<<endl;
        return s.substr(res_start,max_len);
         */

        /*马拉车算法*/
        string t = "$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }
        // Process t
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {   //更新半径和中心
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
