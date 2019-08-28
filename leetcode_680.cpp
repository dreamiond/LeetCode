//leetcode680:Valid Palindrome II
/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		if (isPalind(s)) return true;
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) break;
			++i; --j;
		}
		//cout << s.substr(0, i) + s.substr(i + 1, s.size() - i - 1) << endl;
		//cout << s.substr(0, j) + s.substr(j + 1, s.size() - j - 1) << endl;
		if (isPalind(s.substr(0, i) + s.substr(i + 1, s.size() - i - 1))) return true;
		if (isPalind(s.substr(0, j) + s.substr(j + 1, s.size() - j - 1))) return true;
		return false;
	}
	bool isPalind(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) return false;
			++i; --j;
		}
		return true;
	}
};

//void main() {
//	string s = "abca";
//	Solution sol;
//	sol.validPalindrome(s);
//}