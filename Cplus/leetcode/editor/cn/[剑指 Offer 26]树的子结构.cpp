//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构) 
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 给定的树 A: 
//
// 3 / \ 4 5 / \ 1 2 给定的树 B： 
//
// 4 / 1 返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 1
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
//
// Related Topics 树 深度优先搜索 二叉树 👍 655 👎 0

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x)  : val(x), left(nullptr), right(nullptr) {}
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
    bool isSameStructure(TreeNode *A, TreeNode *B) {
        if (!B) return true;
        if (!A) return false;

        if (A->val != B->val) return false;
        return isSameStructure(A->left, B->left) && isSameStructure(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A && !B) return true;
        if (!A || !B) return false;

        if(isSameStructure(A, B)) return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
