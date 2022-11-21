//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
//
// Related Topics 栈 递归 链表 双指针 👍 351 👎 0

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

class SolutionBruteForce {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;

        auto ptr = head;
        while(ptr != nullptr) {
            result.push_back(ptr->val);
            ptr = ptr->next;
        }

        return vector<int>(result.rbegin(), result.rend());
    }
}; 

// TLE
class SolutionRecursive {
public:
    ListNode* reverseRecursive(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto ptr = reverseRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;

        return ptr;
   }        

    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        auto ptr = reverseRecursive(head);
        while(ptr != nullptr) {
            result.push_back(ptr->val);
        }
        return result;
    }
}; 

class Solution {
public:
    ListNode* reverse(ListNode *head) {
        ListNode *cur = nullptr, *pre = head;
        while(pre){
            auto t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur; 
   }        

    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        auto ptr = reverse(head);
        while(ptr != nullptr) {
            result.push_back(ptr->val);
            ptr = ptr->next;
        }
        return result;
    }
}; 

//leetcode submit region end(Prohibit modification and deletion)
