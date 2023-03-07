// 20 有效的括号

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 每个右括号都有一个对应的相同类型的左括号。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 仅由括号 '()[]{}' 组成 
// 
//
// Related Topics 栈 字符串 👍 3775 👎 0

#include <string>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) return false;
                char curTop = stk.top();
                if (match(curTop, s[i])) stk.pop();
                else return false;
            }
        }

        if (stk.empty()) return true;
        return false;
    }

    bool match(char a, char b) {
        if (a == '(' && b == ')') return true;
        if (a == '[' && b == ']') return true;
        if (a == '{' && b == '}') return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


