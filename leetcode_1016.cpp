//leetcode1016:Binary String With Substrings Representing 1 To N
/*
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.



Example 1:

Input: S = "0110", N = 3
Output: true
Example 2:

Input: S = "0110", N = 4
Output: false


Note:

1 <= S.length <= 1000
1 <= N <= 10^9
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
	bool queryString(string S, int N) {
		for (int i = 1; i <= N; ++i) {
			if (S.find(int2bs(i)) == S.npos) return false;
		}
		return true;
	}
	string int2bs(int n) {
		string res = "";
		while (n) {
			res = (n & 1) ? "1" + res : "0" + res;
			n = n >> 1;
		}
		return res;
	}
};