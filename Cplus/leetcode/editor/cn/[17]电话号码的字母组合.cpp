// 17 电话号码的字母组合

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2292 👎 0

#include <vector>
#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string symbols[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mon", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        if (digits.empty()) return ans;

        ans.push_back("");

        for (int i = 0;i < digits.size();i++) {
            int num = digits[i] - '0';
            vector<string> new_ans;

            for (const string& str : ans) {
                for (char symbol : symbols[num]) {
                    new_ans.push_back(str + symbol);
                }
            }
            ans.swap(new_ans);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


