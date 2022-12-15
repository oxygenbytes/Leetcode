//输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。 
//
// 例如： 
//
// 给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 10000 
// 
//
// 注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-
//tree/ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 220 👎 0

#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SolutionRecursion {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        return max(maxDepth(root->left), maxDepth(root->right))+ 1;
    }
};


class SolutionBFS {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q({root});

        int depth = 0;

        while(!q.empty()) {
            for (int i = q.size() - 1;i >= 0;i--) {
                auto temp = q.front();q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            depth ++;
        }
        return depth;
    }
};


class Solution {
public:
    int maxDepthDFS(TreeNode* root) {
        if (!root) return 0;

        int depth = 0;
        stack<TreeNode*> stk({root});
        TreeNode dummy(-1);
        TreeNode *last = &dummy;
        while(!stk.empty()) { // post order
            depth = max(depth, int(stk.size()));
            TreeNode* cur = stk.top();
            if (cur->left && cur->left != last && cur->right != last) stk.push(cur->left);
            else if (cur->right && cur->right != last) stk.push(cur->right);
            else stk.pop(), last = cur;
        }

        return depth;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
