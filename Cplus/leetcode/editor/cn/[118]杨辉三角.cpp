// 118 杨辉三角

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// 
//
// 示例 2: 
//
// 
//输入: numRows = 1
//输出: [[1]]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= numRows <= 30 
// 
//
// Related Topics 数组 动态规划 👍 944 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> f;

        for (int i = 0;i < numRows;i++) {
            vector<int> line(i+1);
            line[0] = line[i] = 1;

            for (int j = 1;j < i;j++) {
                line[j] = f[i-1][j-1] + f[i-1][j];
            }
            f.push_back(line);
        }

        return f;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


