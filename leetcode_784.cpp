//leetcode784:Letter Case Permutation
/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		trial(S, 0, res);
		return res;
	}
	void trial(string S, int index, vector<string> &res) {
		if (index == S.size()) {
			res.push_back(S);
			return;
		}
		if (!isalpha(S[index])) {
			//该位是数字
			trial(S, index+1, res);
		}
		else {
			//该位是字母
			S[index] = tolower(S[index]);
			trial(S, index+1, res);
			S[index] = toupper(S[index]);
			trial(S, index+1, res);
		}
	}
};

//void main() {
//	string s = "a1b2";
//	Solution sol;
//	sol.letterCasePermutation(s);
//}