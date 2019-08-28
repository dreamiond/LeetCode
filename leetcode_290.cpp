//leetcode290:Word Pattern
/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <sstream>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> cDict;
		unordered_map<string, char> sDict;
		vector<string> s;
		istringstream is(str);
		string tmp;
		while (is >> tmp) s.push_back(tmp);
		if (pattern.size() != s.size()) return false;
		for (int i = 0; i<s.size(); ++i) {
			if (cDict.find(pattern[i]) == cDict.end()) {
				cDict[pattern[i]] = s[i];
			}
			else {
				if (cDict[pattern[i]] != s[i]) return false;
			}
			if (sDict.find(s[i]) == sDict.end()) {
				sDict[s[i]] = pattern[i];
			}
			else {
				if (sDict[s[i]] != pattern[i]) return false;
			}
		}
		return true;
	}
};