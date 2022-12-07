//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= matrix.length <= 100 
// 0 <= matrix[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
//
// Related Topics 数组 矩阵 模拟 👍 473 👎 0

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionSimulate {
public:
    // https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/
    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        vector<int> ans;

        if (matrix.empty()) return ans;

        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;

        while (true) {
            // from left to right 
            for (int i = l; i <= r; i++) ans.push_back(matrix[t][i]);
            if (++t > b) break;
            // from top to bottom
            for (int i = t; i <= b; i++) ans.push_back(matrix[i][r]);
            if (--r < l) break;
            // from right to left 
            for (int i = r; i >= l; i--) ans.push_back(matrix[b][i]);
            if (--b < t) break;
            // from bottom to top
            for (int i = b; i >= t; i--) ans.push_back(matrix[i][l]);
            if (++l > r) break;
        }

        return ans;
    }
};

class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (!m) return ans;
        int n = matrix[0].size();
        if (!n) return ans;

        vector <vector<bool>> vis(m, vector<bool>(n, false));

        int x = 0, y = 0, d = 1;

        for (int i = 0; i < n * m; i++) {
            ans.push_back(matrix[x][y]);
            vis[x][y] = true;

            int xx = x + dx[d];
            int yy = y + dy[d];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || vis[xx][yy]) {
                d = (d + 1) % 4;
                // when get into this if condition, suggest need turn around and re-calc
                xx = x + dx[d];
                yy = y + dy[d];
            }
            x = xx, y = yy;
        }

        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
