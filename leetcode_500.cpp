//leetcode500:Keyboard Row
/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_set<char> line1 = { 'q','w', 'e','r', 't','y', 'u','i', 'o','p', 'Q','W', 'E','R', 'T','Y', 'U','I', 'O','P' };
		unordered_set<char> line2 = { 'a','s', 'd','f', 'g','h', 'j','k', 'l','A', 'S','D', 'F','G', 'H','J', 'K','L' };
		unordered_set<char> line3 = { 'z','x', 'c','v', 'b','n', 'm','Z', 'X','C', 'V','B', 'N','M' };
		vector<string> res;
		for (auto word : words) {
			if (allInLine(word, line1) || allInLine(word, line2) || allInLine(word, line3)) res.push_back(word);
		}
		return res;
	}
	bool allInLine(string s,unordered_set<char> line) {
		for (auto letter : s) {
			if (line.find(letter) == line.end()) return false;
		}
		return true;
	}
};