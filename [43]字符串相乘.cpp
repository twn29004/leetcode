//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 示例 1: 
//
// 输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 说明： 
//
// 
// num1 和 num2 的长度小于110。 
// num1 和 num2 只包含数字 0-9。 
// num1 和 num2 均不以零开头，除非是数字 0 本身。 
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。 
// 
// Related Topics 数学 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    string Add(string num1,string num2){
        string res = "";
        int carry = 0;
        int i = 0,j = 0;

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        while(i < num1.length() && j < num2.length()){
            int tmp = carry;
            tmp += num1[i] - 48;
            tmp += num2[i] - 48;
            stringstream stream;
            stream << tmp % 10;
            res += stream.str();
            carry = tmp / 10;
            i ++;
            j ++;
        }

        if(i < num1.length()){
            while(i < num1.length() && carry){
                int tmp;
                tmp = num1[i] - 48 + carry;
                stringstream stream;
                stream << tmp % 10;
                res += stream.str();
                carry = tmp / 10;
                i ++;
            }
            if(i < num1.length()){
                res += num1.substr(i);
            }
        }

        if(j < num2.length()){
            while (j < num2.length() && carry){
                int tmp = num2[j] - 48 + carry;
                stringstream stream;
                stream << tmp % 10;
                res += stream.str();
                carry = tmp / 10;
                j ++;
            }
            if(j < num2.length()){
                res += num2.substr(j);
            }
        }

        if(carry){
            res += "1";
        }

        reverse(res.begin(),res.end());
        return res;
    }

    bool Judge(string str){
        if(str.length() == 1 && str[0] - 48 == 0){
            return true;
        }
        return false;
    }

    string multiply(string num1, string num2) {
        if(num1.length() == 0 || num2.length() == 0){
            return "";
        }
        if(Judge(num1) || Judge(num2)){
            return "0";
        }
       string res = "0";
       int len1 = num1.length();
       int len2 = num2.length();
       int cnt = 0;   // 统计有几个零，加速运算

       while(num1[len1 - 1] == '0'){
           len1 --;
           cnt ++;
       }
       while(num2[len2 - 1] == '0'){
           len2 --;
           cnt ++;
       }


       num1 = num1.substr(0,len1);
       num2 = num2.substr(0,len2);


       int carry = 0;              // 表示进位
       if(len1 > len2){            // 保证位数少的是num1
            swap(num1,num2);
            swap(len1,len2);
        }

       reverse(num1.begin(),num1.end());
       reverse(num2.begin(),num2.end());
       string zero = "";
       for(int i = 0;i < len1;i ++){
           string tmp;
           int t_i = num1[i] - 48;
           carry = 0;
           if(i > 0){
               zero += "0";
           }

           for(int j = 0;j < len2;j ++){
               int t_res = (t_i * (num2[j] - 48) + carry);
               stringstream stream;
               stream << t_res % 10;
               tmp += stream.str();
               carry = t_res / 10;
           }
           if(carry){
               stringstream stream;
               stream << carry;
               tmp += stream.str();
           }
           reverse(tmp.begin(),tmp.end());
           tmp += zero;
           res = Add(res,tmp);
       }

       res += string(cnt,'0');
       return res;
    }
    /*
     * 19:19	info
			解答成功:
			执行耗时:368 ms,击败了5.05% 的C++用户
			内存消耗:11.1 MB,击败了17.50% 的C++用户
            这尼玛
     */
};
//leetcode submit region end(Prohibit modification and deletion)
