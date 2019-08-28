//leetcode819:Most Common Word
/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.



Example:

Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

//class Solution {
//public:
//	string mostCommonWord(string paragraph, vector<string>& banned) {
//		unordered_map<string, int> dict;
//		unordered_set<string> banDict;
//		for (auto s : banned) {
//			banDict.insert(s);
//		}
//
//		int start = 0, end = 0;
//		while (end < paragraph.size()) {
//			if (isalpha(paragraph[end])) {
//				++end;
//			}
//			else {
//				if (start != end) {
//					string tmp = normalization(paragraph.substr(start, end - start));
//					if (banDict.find(tmp) == banDict.end()) ++dict[tmp];
//				}
//				start = end + 1;
//				end = start;
//			}
//		}
//		if (start < paragraph.size()) {
//			string tmp = normalization(paragraph.substr(start, end - start));
//			if (banDict.find(tmp) == banDict.end()) ++dict[tmp];
//		}
//
//		int max = 0;
//		string res = "";
//		for (auto i : dict) {
//			if (i.second > max) {
//				max = i.second;
//				res = i.first;
//			}
//		}
//		return res;
//	}
//
//	string normalization(string str) {
//		string res = "";
//		for (auto c : str) {
//			if (isalpha(c)) {
//				res = res + char(tolower(c));
//			}
//		}
//		return res;
//	}
//};

class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_map<string, int> dict;
		unordered_set<string> banDict(banned.begin(), banned.end());

		for (auto &c : paragraph) {
			if (!isalpha(c)) c = ' ';
			else c = tolower(c);
		}

		stringstream ss(paragraph);
		string tmp = "";
		int max = 0;
		string res = "";
		while (ss >> tmp) {
			if (banDict.find(tmp) == banDict.end()) {
				++dict[tmp];
				if (dict[tmp] > max) {
					res = tmp;
					max = dict[tmp];
				}
			}
		}

		return res;
	}
};