//leetcode570:Perfect Number
/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
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
	bool checkPerfectNumber(int num) {
		if (num < 2) return false;
		return num == divisorsSum(num);
	}
	int divisorsSum(int num) {
		int res = 0;
		for (int i = 1; i < num; ++i) {
			if (num%i == 0) res += i;
		}
		return res;
	}
};