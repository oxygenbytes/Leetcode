// 剑指 Offer 51 数组中的逆序对

//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 931 👎 0

#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int result = merge(nums, 0, nums.size() - 1);

        // to do merge sort and calc result
       //  for (auto x: nums) cout << x << " ", cout << endl;

        return result;
    }

    int merge(vector<int> &nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + right >> 1;

        vector<int> temp;

        int i = left, j = mid + 1;

        int res = merge(nums, left, mid) + merge(nums, mid + 1, right);

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]), res += mid - i + 1;
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        i = left;

        for (auto x: temp) {
            nums[i++] = x;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


