//leetcode20:Valid Parentheses
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
public:
	bool isRev(char a, char b) {
		return (a == '('&&b == ')') || (a == '{'&&b == '}') || (a == '['&&b == ']');
	}
	bool isValid(string s) {
		if (s.size() == 0) return true;
		stack<char> stk;
		for (auto c : s) {
			if (stk.empty()) stk.push(c);
			else {
				if (isRev(stk.top(), c)) stk.pop();
				else stk.push(c);
			}
		}
		return stk.empty();
	}
};