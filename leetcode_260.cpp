//leetcode260:Single Number III
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
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
	vector<int> singleNumber(vector<int>& nums) {
		int diff = 0;
		for (auto num : nums) diff ^= num;
		diff &= -diff;
		vector<int> res(2, 0);
		for (auto num : nums) {
			if ((num&diff) == 0) {
				res[0] ^= num;
			}
			else {
				res[1] ^= num;
			}
		}
		return res;
	}
};