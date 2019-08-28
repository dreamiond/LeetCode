//leetcode541:Reverse String II
/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int start = 0, end = k - 1; start < s.size(); start += 2 * k, end += 2 * k) {
			reverse(s, start, end);
		}
		return s;
	}
	void reverse(string &s, int start, int end) {
		stack<char> stk;
		for (int i = start; i < s.size() && i < end + 1; ++i) stk.push(s[i]);
		while (!stk.empty()) {
			s[start++] = stk.top();
			stk.pop();
		}
	}
};