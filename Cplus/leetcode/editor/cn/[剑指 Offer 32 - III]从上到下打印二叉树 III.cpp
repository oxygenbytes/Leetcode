//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
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
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
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
// Related Topics 树 广度优先搜索 二叉树 👍 259 👎 0

#include <vector>
#include <queue>

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
class Solution {
public:
    vector <vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector <vector<int>> ans;
        vector<int> temp;
        queue < TreeNode * > q({root});
        bool flag = true;
        while (!q.empty()) {
            temp.clear();

            for (int i = q.size() - 1; i >= 0; i--) {
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (!flag) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
