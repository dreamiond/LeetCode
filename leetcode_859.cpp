//leetcode859:Buddy Strings
/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
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
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size()) return false;
		vector<int> dif;
		unordered_map<char, int> dic;
		for (int i = 0; i < A.size(); ++i) {
			++dic[A[i]];
			if (A[i] != B[i]) dif.push_back(i);
		}
		if (dif.size() == 0) {
			for (auto c : dic) if (c.second > 1) return true;
			return false;
		}
		if (dif.size() != 2) return false;
		swap(A[dif[0]], A[dif[1]]);
		return A == B;
	}
};