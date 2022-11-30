//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。 
//
// 
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
//输入：board = [["a","b"],["c","d"]], word = "abcd"
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
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
//
// Related Topics 数组 回溯 矩阵 👍 710 👎 0

#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(vector <vector<char>> &board, int x, int y, string word, int idx) {
        char curChar = board[x][y];
        if (idx == word.size() - 1 && curChar == word[idx]) return true;
        if (curChar != word[idx]) return false;

        board[x][y] = '@';
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if ((xx >= 0 && xx < board.size()) &&
                (yy >= 0 && yy < board[0].size()) &&
                board[xx][yy] != '@') {
                if (dfs(board, xx, yy, word, idx + 1)) return true;
            }
        }
        board[x][y] = curChar;
        return false;
    }

public:
    bool exist(vector <vector<char>> &board, string word) {
        if (word.size() == 0) return true;

        int m = board.size(), n = 0;
        if (m >= 1) n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j] && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
