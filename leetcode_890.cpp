//leetcode890:Find and Replace Pattern
/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.

You may return the answer in any order.



Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.


Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
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
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;
		for (auto word : words) {
			if (match(word, pattern)) {
				res.push_back(word);
			}
		}
		return res;
	}

	bool match(string word, string pattern) {
		if (word.size() != pattern.size()) return false;
		if (word == pattern) return true;
		unordered_map<char, char> w2p, p2w;
		for (int i = 0; i < word.size(); ++i) {
			if (w2p.find(word[i]) != w2p.end()) {
				//找到了
				if (w2p[word[i]] != pattern[i]) return false;
			}
			else {
				//没找到
				w2p[word[i]] = pattern[i];
			}
			if (p2w.find(pattern[i]) != p2w.end()) {
				//找到了
				if (p2w[pattern[i]] != word[i]) return false;
			}
			else {
				//没找到
				p2w[pattern[i]] = word[i];
			}
		}
		return true;
	}
};