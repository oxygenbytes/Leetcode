// 剑指 Offer 49 丑数

//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。 
//
// 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
//
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 👍 411 👎 0

#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(1, 1);

        int x = 0, y = 0, z = 0;

        // 1 is the smallest ugly number
        // new≠ ugly number came from old ugly number
        while(--n) {
            int t = min(nums[x] * 2, min(nums[y] * 3, nums[z] * 5));

            nums.push_back(t);

            if (nums[x] * 2 == t) x++;
            if (nums[y] * 3 == t) y++;
            if (nums[z] * 5 == t) z++;
        }

        return nums.back(); 
    }
};
//leetcode submit region end(Prohibit modification and deletion)


