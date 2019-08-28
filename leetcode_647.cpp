//leetcode647:Palindromic Substrings
/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Note:

The input string length won't exceed 1000.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

//class Solution {
//public:
//	int countSubstrings(string s) {
//		int n = s.size();
//		vector<vector<bool>> dp(n, vector<bool>(n, false));
//		for (int i = 0; i < n; ++i) {
//			dp[i][i] = true;
//			if (i < n - 1 && s[i] == s[i + 1]) dp[i][i + 1] = true;
//		}
//		for (int dis = 2; dis < n; ++dis) {
//			for (int i = 0; i + dis < n; ++i) {
//				//i=i,j=i+dis
//				dp[i][i + dis] = (s[i] == s[i + dis]) && dp[i + 1][i + dis - 1];
//			}
//		}
//		int res = 0;
//		for (auto line : dp) {
//			for (auto i : line) {
//				if (i) ++res;
//			}
//		}
//		return res;
//	}
//};


class Solution {
public:
	int countSubstrings(string s) {
		int count = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			helper(s, i, i, count);
			helper(s, i, i + 1, count);
		}
		return count;
	}

	void helper(const string &s, int left, int right, int &count) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			++count;
			--left;
			++right;
		}
	}
};