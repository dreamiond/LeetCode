//leetcode557:Reverse Words in a String III
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		string res;
		stack<char> stk;
		for (auto letter : s) {
			if (letter != ' ') {
				stk.push(letter);
			}
			else {
				while (!stk.empty())
				{
					res += stk.top();
					stk.pop();
				}
				res += ' ';
			}
		}
		while (!stk.empty())
		{
			res += stk.top();
			stk.pop();
		}
		return res;
	}
};