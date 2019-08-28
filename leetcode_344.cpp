//leetcode344:Reverse String
/*
Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string res;
		stack<char> stk;
		for (auto i : s) stk.push(i);
		while(!stk.empty()){
			res += stk.top();
			stk.pop();
		}
		return res;
	}
};