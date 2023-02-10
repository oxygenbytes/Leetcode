// 139 单词拆分

//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。 
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 
//
// 示例 2： 
//
// 
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s 和 wordDict[i] 仅有小写英文字母组成 
// wordDict 中的所有字符串 互不相同 
// 
//
// Related Topics 字典树 记忆化搜索 哈希表 字符串 动态规划 👍 1936 👎 0

#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionBruteForce {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        return hasWord(s, us);
    }

    bool hasWord(string s, unordered_set<string>& us) {
        if (us.count(s)) return true;

        for (int i = 0;i < s.size();i++) {
            string subStr = s.substr(0, i);
            string leftStr = s.substr(i);
            if (us.count(subStr) && hasWord(leftStr, us)) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;
        for (int i = 1;i <= s.size();i++) {
            for (int j = i;j >= 0;j--) {
                if (us.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

//leetcode submit region end(Prohibit modification and deletion)


