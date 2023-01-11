// 剑指 Offer 66 构建乘积数组

//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[
//i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。 
//
// 
//
// 示例: 
//
// 
//输入: [1,2,3,4,5]
//输出: [120,60,40,30,24] 
//
// 
//
// 提示： 
//
// 
// 所有元素乘积之和不会溢出 32 位整数 
// a.length <= 100000 
// 
//
// Related Topics 数组 前缀和 👍 284 👎 0

#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        // C[i]=A[0]×A[1]×...×A[i-1]=C[i-1]×A[i-1]
        // D[i]=A[i+1]×...×A[n-1]=D[i+1]×A[i+1]
        // B[i]=C[i]×D[i]

        if (a.empty()) return {};

        vector<int> ans(a.size(), 0);
        ans[0] = 1;

        for (int i = 1, multi = a[0];i < a.size(); i++) {
            ans[i] = multi;
            multi *= a[i];
        }

        for (int i = a.size() - 2, multi = a[a.size() - 1];i >= 0;i--){
            ans[i] *= multi;
            multi *= a[i];
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


