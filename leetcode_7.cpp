//leetcode7:Reverse Integer
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
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
	int reverse(int x) {
		if (x == INT_MIN) return 0;
		bool pos = true;
		if (x < 0) {
			pos = false;
			x = -x;
		}
		vector<int> revNum;
		while (x) {
			revNum.push_back(x % 10);
			x /= 10;
		}
		long res = 0;
		for (long i = revNum.size() - 1,k = 1; i >= 0; --i) {
			res += k*revNum[i];
			k *= 10;
		}
		if (res != (int)res) return 0;
		if (pos) return (int)res;
		return -(int)res;
	}
};