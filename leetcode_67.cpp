//leetcode57:Add Binary
/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
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
	string addBinary(string a, string b) {
		int n = max(a.size(), b.size()) + 1;
		a = string(n - a.size(), '0') + a;
		b = string(n - b.size(), '0') + b;
		int jinwei = 0;
		for (int i = n - 1; i >= 0; --i) {
			int tmp = a[i] - '0' + b[i] - '0' + jinwei;
			if (tmp > 1) {
				a[i] = '0' + tmp - 2;
				jinwei = 1;
			}
			else {
				a[i] = tmp + '0';
				jinwei = 0;
			}
		}
		if (a[0] == '0') a = a.substr(1, a.size() - 1);
		return a;
	}
};