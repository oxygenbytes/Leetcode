//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直
//到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？ 
//
// 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 12
//解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物 
//
// 
//
// 提示： 
//
// 
// 0 < grid.length <= 200 
// 0 < grid[0].length <= 200 
// 
//
// Related Topics 数组 动态规划 矩阵 👍 343 👎 0

#include <vector>
#include <numeric>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionDP {
public:
    int maxValue(vector <vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size(); // grid.size() > 0

        vector <vector<int>> dp(m + 1, vector<int>(n + 1)); // allocate 1 row and column

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp.back().back();
    }
};

// TLE
class SolutionDFS {
private:
    int res = INT_MIN; // res
    vector<int> path; // DFS path
    int m, n;
public:
    int maxValue(vector <vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        dfs(grid, 0, 0);
        return res;
    }

    void dfs(vector <vector<int>> &grid, int x, int y) {
        if (x >= m || y >= n) {
            return;
        }

        path.push_back(grid[x][y]);

        if (x == m - 1 && y == n - 1) {
            int temp = accumulate(path.begin(), path.end(), 0);
            if (temp > res) res = temp;
        }

        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);

        path.pop_back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
