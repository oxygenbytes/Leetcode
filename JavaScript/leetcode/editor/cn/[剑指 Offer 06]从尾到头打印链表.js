/**
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 

 

 示例 1： 

 输入：head = [1,3,2]
输出：[2,3,1] 

 

 限制： 

 0 <= 链表长度 <= 10000 

 Related Topics 栈 递归 链表 双指针 👍 362 👎 0

*/

// Definition for singly-linked list.
function ListNode(val) {
    this.val = val;
    this.next = null;
}

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrintBruteForce = function(head) {
    let arr = [];

    let ptr = head;
    while (ptr != null) {
        arr.push(ptr.val);
        ptr = ptr.next;
    }

    return arr.reverse();
};

/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrintRecursive = function(head) {
    let newHead = recursive(head);
    let arr = [];
    while(newHead) {
        arr.push(newHead.val);
        newHead = newHead.next;
    }
    return arr;
};


/**
 * @param {ListNode} head
 * @return {ListNode} 
 */
var recursive = function(head) {
    if (!head || !head.next) return head;

    let newHead = recursive(head.next);
    head.next.next = head;
    head.next = null;

    return newHead;
}

/**
 *
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrint = function(head) {
    let arr = [];

    let newHead = insertHead(head);
    while(newHead) {
        arr.push(newHead.val);
        newHead = newHead.next;
    }

    return arr;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var insertHead = function (head) {
    let pre = head, cur = null;
    while(pre) {
        let temp = pre.next;
        pre.next = cur;
        cur = pre;
        pre = temp;
    }

    return cur;
}
//leetcode submit region end(Prohibit modification and deletion)
