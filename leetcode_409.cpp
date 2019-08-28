//leetcode409:Longest Palindrome
/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> dict;
		for (auto c : s) {
			++dict[c];
		}
		int res = 0;
		bool hasOddNum = false;
		for (auto letter : dict) {
			if (isOdd(letter.second)) {
				hasOddNum = true;
				if (letter.second != 1) {
					res += letter.second - 1;
				}
			}
			else {
				res += letter.second;
			}
		}
		if (hasOddNum) ++res;
		return res;
	}
	bool isOdd(int num) {
		return num % 2;
	}
};