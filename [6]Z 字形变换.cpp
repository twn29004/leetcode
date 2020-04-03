//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。 
//
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下： 
//
// L   C   I   R
//E T O E S I I G
//E   D   H   N
// 
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。 
//
// 请你实现这个将字符串进行指定行数变换的函数： 
//
// string convert(string s, int numRows); 
//
// 示例 1: 
//
// 输入: s = "LEETCODEISHIRING", numRows = 3
//输出: "LCIRETOESIIGEDHN"
// 
//
// 示例 2: 
//
// 输入: s = "LEETCODEISHIRING", numRows = 4
//输出: "LDREOEIIECIHNTSG"
//解释:
//
//L     D     R
//E   O E   I I
//E C   I H   N
//T     S     G 
// Related Topics 字符串


//leetcode submit region begin(Prohibit modification and deletion)

/*
 * 	terminate called after throwing an instance of 'std::logic_error'
 * 	由于没有对特殊情况进行判读，导致对空字符串进行操作产生的错误
 * */

class Solution {
public:
    string convert(string s, int numRows) {


        if(numRows == 0 || numRows == 1) return s;
        if(s.length() == 0) return s;


        const int len = s.length();
        cout<<"len = "<<len<<endl;
        int h_num = len / (2 * numRows - 2) + 1;
        cout<<"h_num = "<<h_num<<endl;
        string res(1,s[0]);
        for(int i = 1;i <= numRows;i ++){
            for(int j = 1;j <= h_num;j ++){
                int index = (j - 1) * (2 * numRows - 2);
                if(i != 1 && i != numRows) {
                   if(index - i + 1 >= 0 && index - i + 1 < len){
                       res += s[index - i + 1];
                       cout<<"中间"<<index - i + 1<<endl;
                   }
                }
                if(index + (i - 1) < len && index + (i - 1) >= 0){
                    res += s[index + (i - 1)];
                    cout<<index + (i - 1)<<endl;
                }
            }
        }
        return  res.substr(1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
