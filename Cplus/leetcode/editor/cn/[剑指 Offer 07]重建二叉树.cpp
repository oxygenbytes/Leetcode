//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
//
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//
//
//
// 示例 1:
//
//
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
//
//
// 示例 2:
//
//
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
//
//
//
//
// 限制：
//
// 0 <= 节点个数 <= 5000
//
//
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
// preorder-and-inorder-traversal/
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 942 👎 0

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
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
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int m = preorder.size(), n = inorder.size();
        if (m != n || m == 0) {
            return nullptr;
        }

        // 前序遍历的节点, 根节点是数组第一个节点
        // 中序遍历的节点，根节点的数值同前序遍历的根节点一样
        for (int i = 0; i < preorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return build(preorder, 0, m - 1, inorder, 0, n - 1);
    }
private:
    TreeNode* build(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl > pr) return nullptr;

        TreeNode *root = new TreeNode(preorder[pl]); // 根节点
        int pos = map[preorder[pl]];

        // https://pic2.zhimg.com/v2-91d2d6b45996edb4602f984d2451ee69_r.jpg
        root->left = build(preorder, pl+1, pl + pos - il, inorder, il, pos -1);
        root->right = build(preorder, pl + pos - il + 1, pr, inorder, pos+1, ir);

        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
