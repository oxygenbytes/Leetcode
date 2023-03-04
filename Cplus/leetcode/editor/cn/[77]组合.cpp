// 77 组合

// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
//
//  你可以按 任何顺序 返回答案。
//
//
//
//  示例 1：
//
//
// 输入：n = 4, k = 2
// 输出：
//[
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
//]
//
//  示例 2：
//
//
// 输入：n = 1, k = 1
// 输出：[[1]]
//
//
//
//  提示：
//
//
//  1 <= n <= 20
//  1 <= k <= n
//
//
//  Related Topics 回溯 👍 1296 👎 0

#include <vector>
#include <iostream>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector <vector<int>> ans;
    vector<int> temp;
    int n, k;

public:
    vector <vector<int>> combine(int n, int k) {
        if (k > n || k <= 0)
            return ans;
        this->n = n, this->k = k;
        dfs(1);
        return ans;
    }

    // this is a tree
    void dfs(int level) {

        if (temp.size() == this->k) {
            ans.push_back(temp);
            return;
        };

        if (this->n - level + 1 < this->k - temp.size())
            return;
        for (int i = level; i <= this->n; i++) {
            temp.push_back(i);
            dfs(i + 1);
            temp.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
