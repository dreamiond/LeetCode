//leetcode415:Add Strings
/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	char add(char a, char b, char c) {
		return a - '0' + b - '0' + c;
	}

	string addStrings(string num1, string num2) {
		int n1 = num1.size(), n2 = num2.size();
		if (n1 > n2) num2 = string(n1 - n2, '0') + num2;
		else num1 = string(n2 - n1, '0') + num1;
		char c = '0';
		string res;
		for (int i = num1.size() - 1; i >= 0; --i) {
			char sum = add(num1[i], num2[i], c);
			if (sum > '9') {
				c = '1';
				sum -= 10;
			}
			else c = '0';
			res = sum + res;
		}
		if (c == '1') res = c + res;
		return res;
	}
};