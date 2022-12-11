//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。 
//
// 要求时间复杂度为O(n)。 
//
// 
//
// 示例1: 
//
// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 10^5 
// -100 <= arr[i] <= 100 
// 
//
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/ 
//
// 
//
// Related Topics 数组 分治 动态规划 👍 627 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // sum is the result of [1...k](1 <= k <= n,sum must end with nums[k])
    // if(sum < 0) sum = nums[i];
    // else sum = sum + nums[i];

    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, cur = 0;

        for (int i = 0;i < nums.size();i++) {
            if (cur < 0) cur = 0;
            cur += nums[i];
            res = max(res, cur);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
