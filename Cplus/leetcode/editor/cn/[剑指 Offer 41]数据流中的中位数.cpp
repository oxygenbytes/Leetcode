// 剑指 Offer 41 数据流中的中位数

//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数
//值排序之后中间两个数的平均值。 
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例 1： 
//
// 输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 
//
// 示例 2： 
//
// 输入：
//["MedianFinder","addNum","findMedian","addNum","findMedian"]
//[[],[2],[],[3],[]]
//输出：[null,null,2.00000,null,2.50000] 
//
// 
//
// 限制： 
//
// 
// 最多会对 addNum、findMedian 进行 50000 次调用。 
// 
//
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-
//stream/ 
//
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 387 👎 0

#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        minHeap.push(num);

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() && maxHeap.top() > minHeap.top()) {
            int m = maxHeap.top(), n = minHeap.top();
            maxHeap.pop(), maxHeap.push(n);
            minHeap.pop(), minHeap.push(m);
        }
    }

    double findMedian() {
        int m = minHeap.size();
        int n = maxHeap.size();

        if (!m) return 0;
        if (m + n & 1) return minHeap.top();
        else return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)


