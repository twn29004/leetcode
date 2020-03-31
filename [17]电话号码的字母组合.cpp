//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 字符串 回溯算法
// 1
// 2 a,b,c
// 3 d,e,f
// 4 g,h,i
// 5 j,k,l
// 6 m,n,o
// 7 p,q,r,s
// 8 t,u,v
// 9 w,x,y,z

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
    void digui(string digits,int loc,string res,vector<string> strs,vector<string>& R){  //i表示处理第几个数
        if(loc == digits.size()){
            R.push_back(res);
            return;
        }
        int num = digits[loc] - 48;  //将字符转化为数字
        string tmp;
        tmp = res;
        for(int i = 0;i < strs[num].size();i ++){
            string t;
            stringstream stream;
            stream << strs[num][i];
            t = stream.str();
            res += t;
            digui(digits,loc + 1,res,strs,R);
            res = tmp;
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> strs(10);
        strs[0] = " ";
        strs[1] = "";
        strs[2] = "abc";
        strs[3] = "def";
        strs[4] = "ghi";
        strs[5] = "jkl";
        strs[6] = "mno";
        strs[7] = "pqrs";
        strs[8] = "tuv";
        strs[9] = "wxyz";
        vector<string> R;
        if(digits.length() == 0) return R;
        string Res = "";
        digui(digits,0,Res,strs,R);
        return R;
        */

    }
};
//leetcode submit region end(Prohibit modification and deletion)
