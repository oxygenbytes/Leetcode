//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
//
//
//
// 例如: 给定二叉树: [3,9,20,null,null,15,7],
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
//
// 返回：
//
// [3,9,20,15,7]
//
//
//
//
// 提示：
//
//
// 节点总数 <= 1000
//
//
// Related Topics 树 广度优先搜索 二叉树 👍 237 👎 0

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SolutionWithQueue {
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;

        queue < TreeNode * > q({root});

        while (!q.empty()) {
            auto k = q.front();
            q.pop();

            ans.push_back(k->val);

            if (k->left) q.push(k->left);
            if (k->right) q.push(k->right);
        }

        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
