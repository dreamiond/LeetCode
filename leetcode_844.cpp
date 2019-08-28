//leetcode844:Backspace String Compare
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0;
		while (i >= 0 || j >= 0) {
			while (i >= 0 && (S[i] == '#' || countA > 0)) {
				S[i] == '#' ? ++countA : --countA;
				--i;
			}
			while (j >= 0 && (T[j] == '#' || countB > 0)) {
				T[j] == '#' ? ++countB : --countB;
				--j;
			}
			if (i < 0 || j < 0) return i == j;
			if (S[i--] != T[j--]) return false;
		}
		return i == j;
	}
};

//void main() {
//	string s = "abc#", t = "abd#";
//	Solution sol;
//	cout << sol.backspaceCompare(s, t);
//}