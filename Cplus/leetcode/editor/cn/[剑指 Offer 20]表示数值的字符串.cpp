//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。 
//
// 数值（按顺序）可以分成以下几个部分： 
//
// 
// 若干空格 
// 一个 小数 或者 整数 
// （可选）一个 'e' 或 'E' ，后面跟着一个 整数 
// 若干空格 
// 
//
// 小数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 下述格式之一： 
// 
// 至少一位数字，后面跟着一个点 '.' 
// 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字 
// 一个点 '.' ，后面跟着至少一位数字 
// 
// 
//
// 整数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 至少一位数字 
// 
//
// 部分数值列举如下： 
//
// 
// ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"] 
// 
//
// 部分非数值列举如下： 
//
// 
// ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"] 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "0"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "e"
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：s = "."
//输出：false 
//
// 示例 4： 
//
// 
//输入：s = "    .1  "
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。 
// 
//
// Related Topics 字符串 👍 406 👎 0

#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, j = s.size() -1;
        while(i < j) {
            if (s[i] != ' ' && s[j] != ' ') break;
            if (s[i] == ' ') i++;
            if (s[j] == ' ') j--;
        }
        s = s.substr(i, j - i + 1);

        if (s.empty()) return false;
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        if ((s[0] == '.' || s[0] == 'e') && s.size() == 1) return false;

        int dot = 0, e = 0;
        for (int i = 0;i < s.size();i++) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            else if (s[i] == '.') { 
                dot++;
                if (e || dot > 1) return false;
            } else if (s[i] == 'e' || s[i] == 'E') {
                e++;
                if (i + 1 >= s.size() || !i ||
                    e > 1 || (i == 1 && s[0] == '.')) return false;
                if (s[i+1] == '+' || s[i+1] == '-') {
                    if (i+2 == s.size()) return false;
                    i++;
                }
            } else return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
