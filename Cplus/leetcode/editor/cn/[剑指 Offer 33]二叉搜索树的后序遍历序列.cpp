//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。 
//
// 
//
// 参考以下这颗二叉搜索树： 
//
//      5
//    / \
//   2   6
//  / \
// 1   3 
//
// 示例 1： 
//
// 输入: [1,6,3,2,5]
//输出: false 
//
// 示例 2： 
//
// 输入: [1,3,2,6,5]
//输出: true 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// 
//
// Related Topics 栈 树 二叉搜索树 递归 二叉树 单调栈 👍 643 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        return verify(postorder, 0, n - 1);
    }

    bool verify(vector<int>& postorder, int left, int right) {
        if (left > right) return true;

        int i;
        for (i = left; i < right;i ++) {
            if (postorder[i] > postorder[right]) break;
        }
        int pivot = i;

        for (;i < right;i++) {
            if (postorder[i] < postorder[right]) {
                return false;
            }
        }

        return verify(postorder, left, pivot - 1) && verify(postorder, pivot, right - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
