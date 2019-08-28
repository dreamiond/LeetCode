//leetcode66:Plus One
/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int jinwei = 1;
		for (int i = digits.size()-1; i >= 0;--i) {
			if (digits[i] + jinwei < 10) {
				digits[i] += jinwei;
				jinwei = 0;
				break;
			}
			else {
				digits[i] = digits[i] + jinwei - 10;
			}
		}
		if (jinwei) digits.insert(digits.begin(), jinwei);
		return digits;
	}
};