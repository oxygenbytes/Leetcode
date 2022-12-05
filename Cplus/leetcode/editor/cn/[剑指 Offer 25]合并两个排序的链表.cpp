//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
//
// 示例1： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4 
//
// 限制： 
//
// 0 <= 链表长度 <= 1000 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
//
// Related Topics 递归 链表 👍 298 👎 0

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1 || !l2) return l1 == nullptr ? l2 : l1;

        ListNode dummy(-1);
        dummy.next = l1->val > l2->val ? l2 : l1;

        ListNode *ptr = &dummy;

        while (l1 && l2) {
            if (l1->val > l2->val) ptr->next = l2, l2 = l2->next;
            else ptr->next = l1, l1 = l1->next;
            ptr = ptr->next;
        }

        if (l1) ptr->next = l1;
        if (l2) ptr->next = l2;

        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
