//leetcode856:Score of Parentheses
/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.


Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6


Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>
#include <stack>

using namespace std;

//使用栈 时间复杂度O(n),空间复杂度O(n)

//class Solution {
//public:
//	void push(stack<int> &stk, int c) {
//		if (c == -1) {//(
//			stk.push(-1);
//		}
//		else if (c == -2) {//)
//			if (stk.top() == -1) {//()->1
//				stk.pop();
//				push(stk, 1);
//			}
//			else {//(x)->2x
//				int num = stk.top() * 2;
//				stk.pop(); stk.pop();
//				push(stk, num);
//			}
//		}
//		else {
//			if (stk.empty() || stk.top() == -1) stk.push(c);
//			else {
//				int num = stk.top() + c;
//				stk.pop();
//				stk.push(num);
//			}
//		}
//	}
//
//	int scoreOfParentheses(string S) {
//		stack<int> stk;
//		for (auto c : S) {
//			if (c == '(') push(stk, -1);
//			else push(stk, -2);
//		}
//		return stk.top();
//	}
//};

class Solution {
public:
	int scoreOfParentheses(string S) {
		int res = 0, l = 0;
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == '(') l++; else l--;
			if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
		}
		return res;
	}
};