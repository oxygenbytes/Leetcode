// 剑指 Offer 37 序列化二叉树

//请实现两个函数，分别用来序列化和反序列化二叉树。 
//
// 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字
//符串反序列化为原始的树结构。 
//
// 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方
//法解决这个问题。 
//
// 
//
// 示例： 
// 
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-
//binary-tree/ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 👍 363 👎 0

#include <string>
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        dfs_s(root, res);
        // cout << res << endl;
        return res;
    }

    void dfs_s(TreeNode *root, string &str) {
        if (!root) {
            str += "null ";
            return;
        }

        str += to_string(root->val) + ' ';
        dfs_s(root->left, str);
        dfs_s(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode *dfs_d(string data, int &u) {
        // return nullptr;
        if (u == data.size()) return nullptr;

        int k = u;

        while (data[k] != ' ') k++;

        if (data[u] == 'n') {
            u = k + 1;
            return nullptr;
        }

        bool flag = false;

        if (data[u] == '-') {
            flag = true;
        }
        int val = 0;
        u = (flag ? u + 1 : u);

        for (int i = u; i < k; i++) {
            val = val * 10 + data[i] - '0';
        }
        if (flag) val = -val;
        u = k + 1;

        auto root = new TreeNode(val);

        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


