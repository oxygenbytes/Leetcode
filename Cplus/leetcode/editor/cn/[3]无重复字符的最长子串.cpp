// 3 无重复字符的最长子串

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 8663 👎 0

#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        unordered_set<char> us;

        for(int i = 0;i < s.size();i++) {
            while(us.find(s[i]) != us.end()) {
                us.erase(s[left++]);
            }
            ans = max(ans, i - left + 1);
            us.insert(s[i]);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


