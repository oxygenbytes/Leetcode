//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 
//
// 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/ 
//
// Related Topics 递归 链表 👍 511 👎 0

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionRecursive {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(-1);
        ListNode *ptr = head;
        ListNode *temp;
        while (ptr) {
            temp = ptr->next;
            ptr->next = dummy.next;
            dummy.next = ptr;
            ptr = temp;
        }

        return dummy.next;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
