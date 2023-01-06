// 剑指 Offer 38 字符串的排列

//输入一个字符串，打印出该字符串中字符的所有排列。
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
//
// Related Topics 字符串 回溯 👍 630 👎 0

#include <string>
#include <vector>
#include <set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:

    set <string> se;
public:
    vector <string> permutation(string s) {
        vector<bool> vis(s.size(), false);
        string cur = "";
        dfs(s, vis, cur);

        vector <string> ans;

        for (auto it = se.begin(); it != se.end(); it++) {
            ans.push_back(*it);
        }

        return ans;
    }

    void dfs(string &str, vector<bool> &vis, string &cur) {
        if (cur.size() == str.size()) {
            se.insert(cur);
            return;
        }

        for (int i = 0; i < str.size(); i++) {
            if (!vis[i]) {
                string temp = cur;
                cur += str[i];
                vis[i] = true;

                dfs(str, vis, cur);

                vis[i] = false;
                cur = temp;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


