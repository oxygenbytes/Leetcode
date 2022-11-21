//找出数组中重复的数字。
//
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
//请找出数组中任意一个重复的数字。
//
// 示例 1：
//
// 输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3
//
//
//
//
// 限制：
//
// 2 <= n <= 100000
//
// Related Topics 数组 哈希表 排序 👍 1005 👎 0

#include <vector>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class SolutionSort {
public:
    int findRepeatNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

class SolutionBruteForce {
public:
    int findRepeatNumber(vector<int> &nums) {
        unordered_set<int> set;

        for (int i = 0;i < nums.size();i++) {
            if (set.count(nums[i])) {
                return nums[i];
            }
            set.insert(nums[i]);
        }

        return -1;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size();i++ ) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
