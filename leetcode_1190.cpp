//leetcode1190:Reverse Substrings Between Each Pair of Parentheses
/*
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.



Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"


Constraints:

0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>

using namespace std;

class Solution {
public:
	//string reverseParentheses(string s) {
	//	if (s.empty() || s.size() == 1) return s;
	//	stack<char> handler;
	//	deque<char> helper;
	//	for (auto c : s) {
	//		if (c != ')') {
	//			handler.push(c);
	//		}
	//		else {
	//			while (handler.top() != '(') {
	//				helper.push_back(handler.top());
	//				handler.pop();
	//			}
	//			handler.pop();
	//			while (!helper.empty()) {
	//				handler.push(helper.front());
	//				helper.pop_front();
	//			}
	//		}
	//	}
	//	stack<char> tmp;
	//	while (!handler.empty()) {
	//		tmp.push(handler.top());
	//		handler.pop();
	//	}
	//	string res = "";
	//	while (!tmp.empty()) {
	//		res = res + tmp.top();
	//		tmp.pop();
	//	}
	//	return res;
	//}

	//µõÕ¨ÌìµÄ³æ¶´Ëã·¨
	string reverseParentheses(string s) {
		int n = s.size();
		vector<int> opened, pair(n);
		string res = "";
		
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') {
				opened.push_back(i);
			}
			else if (s[i] == ')') {
				int j = opened.back();
				opened.pop_back();
				pair[i] = j;
				pair[j] = i;
			}
		}

		for (int i = 0, d = 1; i < n; i += d) {
			if (s[i] == '(' || s[i] == ')') {
				i = pair[i];
				d = -d;
			}
			else {
				res += s[i];
			}
		}
		return res;
	}
};