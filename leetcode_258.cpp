//leetcode258:Add Digits
/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int addDigits(int num) {
		while (num>9) {
			num = getDigitsNum(getDigits(num));
		}
		return num;
	}
	vector<int> getDigits(int num) {
		vector<int> res;
		while (num) {
			res.push_back(num % 10);
			num /= 10;
		}
		return res;
	}
	int getDigitsNum(vector<int> v) {
		int res = 0;
		for (auto i : v) {
			res += i;
		}
		return res;
	}
};