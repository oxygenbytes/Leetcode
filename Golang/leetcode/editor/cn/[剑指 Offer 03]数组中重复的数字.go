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

package cn

import "sort"

// leetcode submit region begin(Prohibit modification and deletion)
func findRepeatNumberBruteForce(nums []int) int {
	set := make(map[int]struct{}, len(nums))
	for _, num := range nums {
		if _, ok := set[num]; ok {
			return num
		}
		set[num] = struct{}{}
	}

	return -1
}

func findRepeatNumberSort(nums []int) int {
	sort.Ints(nums)
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			return nums[i]
		}
	}
	return -1
}

func findRepeatNumber(nums []int) int {
	for i := 0; i < len(nums); i++ {
		for nums[i] != i {
			if nums[nums[i]] == nums[i] {
				return nums[i]
			}
			nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
		}
	}
	return -1
}

//leetcode submit region end(Prohibit modification and deletion)
