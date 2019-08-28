//leetcode14:Longest Common Prefix
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
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
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		int firstNotCommon = strs[0].size();
		int n = strs[0].size();
		for (int i = 1; i < strs.size(); ++i) {
			for (int j = 0; j < n; ++j) {
				if (strs[0][j] != strs[i][j]) {
					firstNotCommon = min(firstNotCommon, j);
					break;
				}
				if (firstNotCommon == 0) return "";
			}
		}
		return strs[0].substr(0, firstNotCommon);
	}
};