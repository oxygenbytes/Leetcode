// 剑指 Offer 05 替换空格

package cn

import "strings"

//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
//
// 👍 410 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
func replaceSpaceBruteForce(s string) string {
	res := ""
	for _, x := range s {
		if x == ' ' {
			res += "%20"
		} else {
			res += string(x)
		}
	}
	return res
}

func replaceSpace(s string) string {
	// return strings.Replace(s, " ", "%20", -1)
	return strings.ReplaceAll(s, " ", "%20")
}

//leetcode submit region end(Prohibit modification and deletion)
