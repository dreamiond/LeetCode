//leetcode821:Shortest Distance to a Character
/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]


Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*vector<int> shortestToChar(string S, char C) {
		vector<int> cPos;
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == C) cPos.push_back(i);
		}
		vector<int> res;
		for (int i = 0; i < S.size(); ++i) {
			int shortestDistance = S.size();
			for (int j = 0; j < cPos.size(); j++) {
				shortestDistance = shortestDistance < abs(i - cPos[j]) ? shortestDistance : abs(i - cPos[j]);
			}
			res.push_back(shortestDistance);
		}
		return res;
	}*/
	vector<int> shortestToChar(string S, char C) {
		int n = S.size();
		vector<int> res(n, n);
		int pos = -n;
		for (int i = 0; i < n - 1; ++i) {
			if (S[i] == C) pos = i;
			res[i] = abs(i - pos);
		}
		for (int i = n - 1; i >= 0; --i) {
			if (S[i] == C) pos = i;
			res[i] = min(res[i], abs(i - pos));
		}
		return res;
	}
};