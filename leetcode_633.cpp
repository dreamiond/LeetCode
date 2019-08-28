//leetcode633:Sum of Square Numbers
/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False
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
	bool judgeSquareSum(int c) {
		int x = sqrt(c / 2);
		int n = sqrt(c);
		while (x <= n) {
			double y = sqrt(c - x*x);
			int tmp = y + 0.5;
			if (abs(y - tmp) < 1e-10) return true;
			++x;
		}
		return false;
	}
};