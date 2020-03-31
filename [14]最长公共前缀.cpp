//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 示例 1: 
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
// 
//
// 示例 2: 
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
// 
//
// 说明: 
//
// 所有输入只包含小写字母 a-z 。 
// Related Topics 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    string LCP(string str1,string str2){
        int len = min(str1.length(),str2.length());
        int i;
        for(i = 0;i < len;i ++){
            if(str1[i] != str2[i]){
                break;
            }
        }
        return i < len ? str1.substr(0,i) : str1.substr(0,i + 1);
    }

    string longestCommonPrefix(vector<string>& strs) {
        /*
        //先找出最短的那个
        int res = 0;
        int tmp = strs.size();
        if(tmp == 0)   //对特殊情况的判读那
            return "";
        int len = strs[0].length();  //要对特殊情况进行判断
            运行失败:
			Line 923: Char 34: runtime error: reference binding to null pointer of type 'struct value_type' (stl_vector.h)
			stdout:
        for(int i = 0;i < strs.size();i ++){   //找出最小长度的字符串,避免越界
            if(len > strs[i].length()){
                len = strs[i].length();
            }
        }
        for(int i = 0;i < len;i ++){
            int j;
            for(j = 0;j < tmp;j ++){
                if(strs[0][i] != strs[j][i])
                    break;
            }
            if(j == tmp){
              res ++;
            }
            else break;   //只要有一次不等就跳出循环
        }
        return strs[0].substr(0,res);
        */

        //上述方法为暴力法
        //官网的水平扫描法
        if(strs.size() == 0)return "";
        int loc = 0;   //找到长度最短的字符串的额位置
        for(int i = 0;i < strs.size();i ++){
            if(strs[i].size() < strs[loc].size()){
                loc = i;
            }
        }
        string res = strs[loc];
        for(int i = 0;i < strs.size();i ++){
            res = LCP(res,strs[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
