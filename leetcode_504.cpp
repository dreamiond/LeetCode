//leetcode504:Base 7
/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		string res = "";
		bool isNegative = false;
		if (num < 0) {
			num = -num;
			isNegative = true;
		}
		while (num) {
			res = to_string(num % 7) + res;
			num /= 7;
		}
		if (isNegative) return "-" + res;
		return res;
	}
};