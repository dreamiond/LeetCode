//leetcode205:Isomorphic Strings
/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
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
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;
		int n = s.size();
		int map1[256] = { 0 }, map2[256] = { 0 };
		for (int i = 0; i < n; ++i) {
			if (map1[s[i]] != map2[t[i]]) return false;
			map1[s[i]] = i+1;
			map2[t[i]] = i+1;
		}
		return true;
	}
};