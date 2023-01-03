//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [4,1,4,6]
//输出：[1,6] 或 [6,1]
// 
//
// 示例 2： 
//
// 输入：nums = [1,2,10,4,1,4,3,3]
//输出：[2,10] 或 [10,2] 
//
// 
//
// 限制： 
//
// 
// 2 <= nums.length <= 10000 
// 
//
// 
//
// Related Topics 位运算 数组 👍 746 👎 0

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        // if ans = [x, y]
        // calc x^y
        int sum = 0;
        for (auto num: nums) sum ^= num;

        // find flag to group x and group y
        int k = 0;
        while (!(sum >> k & 1)) k++;

        // calc x, y
        int x = 0;
        for (auto num: nums) {
            if (num >> k & 1) x ^= num;
        }
        int y = sum ^ x;

        return vector < int > {x, y};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
