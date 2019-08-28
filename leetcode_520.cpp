//leetcode520:Detect Capital
/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		if (case1(word) || case2(word) || case3(word)) return true;
		return false;
	}
	bool case1(string word) {
		for (auto i : word) {
			if (islower(i)) return false;
		}
		return true;
	}
	bool case2(string word) {
		for (auto i : word) {
			if (isupper(i)) return false;
		}
		return true;
	}
	bool case3(string word) {
		if (islower(word[0])) return false;
		for (int i = 1; i < word.size(); ++i) {
			if (isupper(word[i])) return false;
		}
		return true;
	}
};