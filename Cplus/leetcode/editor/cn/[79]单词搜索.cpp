// 79 单词搜索

//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"SEE"
//输出：true
// 
//
// 示例 3： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
//
// Related Topics 数组 回溯 矩阵 👍 1529 👎 0

#include <vector>
#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;

        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int len) {
        if (word[len] != board[x][y]) return false;
        if (len == word.size() - 1) return true;

        char temp = board[x][y];
        board[x][y] = '@';
        
        for (int i = 0;i < 4;i++) {
            int m = x + dx[i];
            int n = y + dy[i];

            if (m >= 0 && m < board.size() && n >= 0 && n < board[0].size() && board[m][n] == word[len+1]) {
                    if(dfs(board, m, n, word, len+1)) {
                        return true;
                    }
                }
        }

        board[x][y] = temp;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


