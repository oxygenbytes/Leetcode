// 5 最长回文子串

//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 6237 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        const int n = s.length();

        int maxLeft = 0;
        int maxLength = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < i;j++){
                if (s[i] == s[j] && ((i - j) <= 2 || dp[j+1][i-1])) {
                    dp[i][j] = true;
                    if (i - j + 1 > maxLength) {
                        maxLeft = j;
                        maxLength = i - j + 1;
                    }
                }
            }
        }

        return s.substr(maxLeft, maxLength);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


