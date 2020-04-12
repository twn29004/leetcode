//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if(strs.size() == 0){
            return res;
        }
        // 将每个字符串的字母按字典序排列作为key插入哈希表中
        map<string,vector<string>> M;
        for(int i = 0;i < strs.size();i ++){
                string tmp = strs[i];
                sort(tmp.begin(),tmp.end());
                M[tmp].push_back(strs[i]);
        }
        // 遍历map中的元素
        map<string,vector<string>>::iterator iter;
        for(iter = M.begin();iter != M.end();iter ++){
            vector<string> tmp;
            tmp = (iter->second);
            res.push_back(tmp);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
