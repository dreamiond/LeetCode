//leetcode28:Implement strStr()
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
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
	int strStr(string haystack, string needle) {
		if (needle == "") return 0;
		int n = needle.size(), m = haystack.size();
		if (m < n) return -1;
		for (int i = 0; i < m - n + 1; ++i) {
			if (haystack[i] == needle[0]) {
				if (haystack.substr(i, n) == needle) return i;
			}
		}
		return -1;
	}
};