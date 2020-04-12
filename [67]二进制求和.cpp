//给你两个二进制字符串，返回它们的和（用二进制表示）。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1: 
//
// 输入: a = "11", b = "1"
//输出: "100" 
//
// 示例 2: 
//
// 输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
// Related Topics 数学 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int i = 0,j = 0;
        int carry = 0;
        string res;

        while(i < a.length() && j < b.length()){
            int tmp = carry;
            tmp += a[i] - 48;
            tmp += b[j] - 48;
            stringstream stream;
            stream << (tmp % 2);
            res += stream.str();
            carry = tmp / 2;
            i ++;
            j ++;
        }

        while(i < a.length()){
            int tmp = carry;
            tmp += a[i] - 48;
            stringstream stream;
            stream << (tmp % 2);
            res += stream.str();
            carry = tmp / 2;
            i ++;
        }

        while(j < b.length()){
            int tmp = carry;
            tmp += b[j] - 48;
            stringstream stream;
            stream << (tmp % 2);
            res += stream.str();
            carry = tmp / 2;
            j ++;
        }

        if(carry){
            res += "1";
        }

        reverse(res.begin(),res.end());
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
