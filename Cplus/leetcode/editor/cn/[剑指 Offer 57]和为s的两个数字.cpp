//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [2,7,11,15], target = 9
//输出：[2,7] 或者 [7,2]
// 
//
// 示例 2： 
//
// 输入：nums = [10,26,30,31,47,60], target = 40
//输出：[10,30] 或者 [30,10]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10^5 
// 1 <= nums[i] <= 10^6 
// 
//
// Related Topics 数组 双指针 二分查找 👍 219 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionTwoPointers {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0, j = nums.size() - 1;i <= j;) {
            if (nums[i] + nums[j] == target) return {nums[i], nums[j]};
            else if (nums[i] + nums[j] < target) i++;
            else j--;
        }

        return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] > target) return {};

            if (bs(nums, target - nums[i])) return {nums[i], target - nums[i]};
        }
        return {};
    }

    bool bs(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        return nums[left] == target;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
