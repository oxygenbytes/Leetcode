// 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
//
//
//
//  示例:
//
//  输入: a = 1, b = 1
// 输出: 2
//
//
//
//  提示：
//
//
//  a, b 均可能是负数或 0
//  结果不会溢出 32 位整数
//
//
//  Related Topics 位运算 数学 👍 370 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int add(int a, int b) {
        // sum = a + b = a ^ b + a & b << 1;
        // if b == 0, the result is a
        // ref: https://pic.leetcode-cn.com/56d56524d8d2b1318f78e209fffe0e266f97631178f6bfd627db85fcd2503205-Picture1.png
        if (b == 0)
            return a;

        return add(a ^ b, (a & b & 0x7fffffff) << 1);
    }
};
// leetcode submit region end(Prohibit modification and deletion)
