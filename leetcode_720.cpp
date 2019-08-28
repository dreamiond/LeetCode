//leetcode720:Longest Word in Dictionary
/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:

	bool canBeRepresented(unordered_set<string> &dict, string s) {
		for (int i = 1; i < s.size(); ++i) {
			if (dict.find(s.substr(0, i)) == dict.end()) return false;
		}
		return true;
	}

	string longestWord(vector<string>& words) {
		unordered_set<string> dict;
		string res = "";
		for (auto s : words) {
			dict.insert(s);
		}
		for (auto s : words) {
			if (canBeRepresented(dict, s)) {
				if (res.size() == s.size()) res = res < s ? res : s;
				else res = res.size() > s.size() ? res : s;
			}
		}
		return res;
	}
};