//leetcode172:Factorial Trailing Zeroes
/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
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
	int trailingZeroes(int n) {
		int res = 0;
		long long i = 5;
		while (n >= i) {
			res += (n / i);
			i *= 5;
		}
		return res;
	}
};