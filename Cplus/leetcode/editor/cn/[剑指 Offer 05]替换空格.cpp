//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
//
// Related Topics 字符串 👍 368 👎 0

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
        const string replaceStr = "%20";
        string str = "";

        for (auto x: s) {
            if (x == ' ') {
                str += replaceStr;
            } else {
                str += x;
            }
        }
        return str;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
