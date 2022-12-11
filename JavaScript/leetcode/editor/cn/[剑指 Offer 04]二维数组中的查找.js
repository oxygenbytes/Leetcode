/*
---
title: "[剑指 Offer 04]二维数组中的查找"
date: 2022-12-12 01:18:11+08:00
draft: true
tags:
  - Leetcode
---
*/

/**
 在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数
 组和一个整数，判断数组中是否含有该整数。



 示例:

 现有矩阵 matrix 如下：


 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]


 给定 target = 5，返回 true。

 给定 target = 20，返回 false。



 限制：

 0 <= n <= 1000

 0 <= m <= 1000



 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

 Related Topics 数组 二分查找 分治 矩阵 👍 835 👎 0

 */

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function (matrix, target) {
    if (!matrix.length || !matrix[0].length) {
        return false;
    }

    for (let x = 0, y = matrix[0].length; x < matrix.length && y >= 0;) {
        if (matrix[x][y] == target) return true;
        else if (matrix[x][y] < target) x++;
        else y--;
    }
    return false;
};
//leetcode submit region end(Prohibit modification and deletion)
