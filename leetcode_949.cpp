//leetcode949:Largest Time for Given Digits
/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.



Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""


Note:

A.length == 4
0 <= A[i] <= 9
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
	string largestTimeFromDigits(vector<int>& A) {
		vector<string> s;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (j == i) continue;
				for (int m = 0; m < 4; ++m) {
					if (m == i || m == j) continue;
					for (int n = 0; n < 4; ++n) {
						if (n == i || n == j || n == m) continue;
						string tmp = to_string(A[i]) + to_string(A[j]) + to_string(A[m]) + to_string(A[n]);
						if (isValidTime(tmp)) {
							s.push_back(tmp);
							cout << tmp << endl;
						}
					}
				}
			}
		}
		if (s.empty()) return "";
		string res = s[0];
		for (auto i : s) {
			if (isLargerTime(i, res)) res = i;
		}
		return res.substr(0, 2) + ":" + res.substr(2, 2);
	}
	bool isValidTime(string s) {
		return  s.substr(0, 2) < "24"&&s.substr(2, 2) < "60";
	}
	bool isLargerTime(string a, string b) {
		for (int i = 0; i < 4; ++i) {
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
		return true;
	}
};

//void main() {
//	vector<int> v{ 1,2,3,4 };
//	Solution sol;
//	cout << sol.largestTimeFromDigits(v) << endl;
//}