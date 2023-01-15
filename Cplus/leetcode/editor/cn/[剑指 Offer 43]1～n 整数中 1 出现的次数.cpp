// 剑指 Offer 43 1～n 整数中 1 出现的次数

//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。 
//
// 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 12
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：n = 13
//输出：6 
//
// 
//
// 限制： 
//
// 
// 1 <= n < 2^31 
// 
//
// 注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/ 
//
// Related Topics 递归 数学 动态规划 👍 392 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
        if(!n) return 0;

        vector<int> digit;
        while(n) digit.push_back(n % 10), n /= 10;

        int ans = 0;

        // ab*c*def
        // case 1(full): [0,ab-1] * (0-9) * [0-999] 
        // case 2(special): ab * [0-c] * def 

        for(int i = digit.size() - 1;i >= 0;i--) {
            int left = 0, right = 0, t = 1;

            for(int j = digit.size() - 1;j > i;j--) left = left * 10 + digit[j];
            for(int j = i - 1;j >= 0;j--) right = right * 10 + digit[j], t *= 10;

            ans += left * t; // case 1
            if (digit[i] == 1) ans += right + 1;
            if (digit[i] > 1) ans += t;

        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


