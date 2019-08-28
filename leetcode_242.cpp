//leetcode242:Valid Anagram
/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> dictS;
		for (auto i : s) {
			++dictS[i];
		}
		for (auto i : t) {
			if (dictS[i] == 0) return false;
			else --dictS[i];
		}
		for (auto i : dictS) {
			if (i.second != 0) return false;
		}
		return true;
	}
};