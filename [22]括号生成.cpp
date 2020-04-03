//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。 
//
// 例如，给出 n = 3，生成结果为： 
//
// [
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]
// 
// Related Topics 字符串 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /*
    //每不就是看这个堆栈是否弹出就好了
    void digui(int n,string& tmp,vector<string>& Res,stack<string>& S,int& count){
        if(S.empty()){
            Res.push_back(tmp);
            return;
        }

        stack<string> t = S;  //保存一下当前的数据
        string tmp1 = tmp;

        //如果要弹出的话
        if(!S.empty()){
            tmp += S.top();
            S.pop();
            count ++;
            digui(n - 1,tmp,Res,S,count);
        }
        //如果选择不弹出
        if(count == 0){
            return;
        }else{
            tmp1 += ")";
            count --;
            digui(n - 1,tmp1,Res,t,count);
        }
    }
*/
    void BackTrack(string tmp,vector<string>& Res,int left,int right,int n){
        if(left == n){   //也就是上面的堆栈中为空
            if(tmp.length() < 2 * n){
                tmp += string(2*n - tmp.length(),')');
                Res.push_back(tmp);
            }
            else {
                Res.push_back(tmp);
            }
            return;
        }

        BackTrack(tmp+"(",Res,left+1,right,n);
        //如果不弹出的话,只有右括号的数目小于左括号的数目才行
        if(right < left) {
            BackTrack(tmp+")",Res,left,right + 1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        //可以看出，第一对括号的右括号的位置一定是奇数，所以可以递推这个来获得所有的组合

    //emmm,上面的代码思路倒是没什么问题，就是写的非常的丑，很丑，导致要么超时，要么超内存，我傻了
    //下面是官网看到的一种方法，可以说写的非常简介，明了
        string tmp;
        vector<string> Res;
        BackTrack(tmp,Res,0,0,n);
        return Res;
    }

    /*
     * 17:17	info
			解答成功:
			执行耗时:4 ms,击败了90.07% 的C++用户
			内存消耗:15.1 MB,击败了59.87% 的C++用户
     * 终归还是菜了点
     */
};
//leetcode submit region end(Prohibit modification and deletion)
