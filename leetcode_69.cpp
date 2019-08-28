//leetcode69:Sqrt(x)
/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
the decimal part is truncated, 2 is returned.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

//class Solution {
//public:
//	int mySqrt(int x) {
//		if (x == 0) return 0;
//		long res = 1;
//		while (res*res <= x) ++res;
//		return res - 1;
//	}
//};

int mysqrt(int x) {
	if (x == 0) return 0;
	double last = 0;
	double res = 1;
	while (abs(last-res)>1e-9)
	{
		last = res;
		res = (res + x / res) / 2;
	}
	return int(res);
}
