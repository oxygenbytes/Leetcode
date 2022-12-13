//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/ 
//
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 383 👎 0

#include <vector>
#include <stack>
#include <iostream>

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class SolutionRecursive {
private:
    vector <vector<int>> res;
    vector<int> cur;

    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        cur.push_back(root->val);
        sum -= root->val;

        if (!root->left && !root->right && !sum) res.push_back(cur);
        dfs(root->left, sum);
        dfs(root->right, sum);

        cur.pop_back();
    }

public:
    vector <vector<int>> pathSum(TreeNode *root, int target) {
        if (!root) return res;
        dfs(root, target);
        return res;
    }
};

class Solution {
private:
    vector <vector<int>> res;
    vector<int> path;

public:
    vector <vector<int>> pathSum(TreeNode *root, int target) {
        if (!root) return res;

        auto dummy = TreeNode(-1); // pre must init
        TreeNode *pre = &dummy, *cur;
        stack < TreeNode *> stk({root});
        path.push_back(root->val);
        int sum = root->val;
        
        while(!stk.empty()) {
            cur = stk.top();
            // 1. has left, and not return from childred => go left => else
            // 2. has right, and not return from right => go right => else 
            // 3. don't go left or right => go parent
            if (cur->left && pre != cur->left && pre != cur->right) {
                stk.push(cur->left);
                sum += cur->left->val;
                path.push_back(cur->left->val);
            } else if (cur->right && pre != cur->right) {
                stk.push(cur->right);
                sum += cur->right->val;
                path.push_back(cur->right->val);
            } else {
                stk.pop();
                cout<<"sum:"<<sum<<" "<<endl;
                if (sum == target && !cur->left && !cur->right) {
                    res.push_back(path);
                }
                sum -= cur->val;
                path.pop_back();
            }
            pre = cur;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
