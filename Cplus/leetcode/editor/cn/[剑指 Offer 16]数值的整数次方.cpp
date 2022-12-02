//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xⁿ）。不得使用库函数，同时不需要考虑大数问题。 
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
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2⁻² = 1/2² = 1/4 = 0.25 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -2³¹ <= n <= 2³¹-1 
// -10⁴ <= xⁿ <= 10⁴ 
// 
//
// 
//
// 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/ 
//
// Related Topics 递归 数学 👍 365 👎 0

#include <math.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        long long absN = abs(n); 

        double result = 1;
        while (absN) {
            if (absN & 1) result = result * x;
            x = x * x;
            absN >>= 1;
        }

        if (n < 0) return 1 / result;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
