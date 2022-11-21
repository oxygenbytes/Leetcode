/*
---
title: "[剑指 Offer 03]数组中重复的数字"
date: 2022-11-15 01:02:46+08:00
draft: true
tags:
  - Leetcode
---
*/

/**
找出数组中重复的数字。 

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找
出数组中任意一个重复的数字。 

示例 1：
输入：[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 
限制：2 <= n <= 100000

Related Topics 数组 哈希表 排序 👍 1002 👎 0
*/

package leetcode.editor.cn;

import java.util.*;

class SolutionBruteForce {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int idx = 0; idx < nums.length; idx++) {
            if (set.contains(nums[idx])) {
                return nums[idx];
            }
            set.add(nums[idx]);
        }
        return -1;
    }
}

class SolutionSort {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0;i < nums.length - 1;i++) {
            if (nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return -1;
    }
}

class Solution {
    public int findRepeatNumber(int[] nums) {
        for (int i = 0;i < nums.length;i++) {
            while(nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                        return nums[i];
                }
                swap(nums, i, nums[i]);
            }
        }
        return -1;
    }

    private static void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
