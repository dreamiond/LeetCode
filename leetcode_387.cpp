//leetcode387:First Unique Character in a String
/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> dict;
		int res = -1;
		for (auto c : s) {
			++dict[c];
		}
		for (int i = 0; i < s.size(); ++i) {
			if (dict[s[i]] == 1) {
				res = i;
				break;
			}
		}
		return res;
	}
};