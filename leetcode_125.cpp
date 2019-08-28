//leetcode125:Valid Palindrome
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string t = "";
		for (auto c : s) {
			if (isalpha(c)) t += tolower(c);
			else if ('0' <= c && c <= '9') t += c;
		}
		cout << t << endl;
		int i = 0, j = t.size() - 1;
		while (i < j) {
			if (t[i] != t[j]) return false;
			++i; --j;
		}
		return true;
	}
};