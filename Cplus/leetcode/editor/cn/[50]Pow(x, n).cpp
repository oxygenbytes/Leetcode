// 50 Pow(x, n)

//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xⁿ ）。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100
// 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25
// 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// n 是一个整数 
// -104 <= xⁿ <= 104 
// 
//
// Related Topics 递归 数学 👍 1132 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1, p = x;
        long long int t = abs(long(n));

        while(t) {
            if (t & 1) ans = ans * p;
            p = p * p;
            t >>= 1;
        }

        return n > 0 ? ans : 1 / ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


