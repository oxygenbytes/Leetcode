//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出
//这个数字。 
//
// 
//
// 示例 1: 
//
// 输入: [0,1,3]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [0,1,2,3,4,5,6,7,9]
//输出: 8 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 10000 
//
// Related Topics 位运算 数组 哈希表 数学 二分查找 👍 329 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;

        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + right >> 1;
            if (nums[mid] > mid) right = mid;
            else left = mid + 1;
        }

        if (nums[left] == left) return nums.size();
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
