//leetcode283:Move Zeroes
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int> res;
		for (auto i : nums) {
			if (i != 0) res.push_back(i);
		}
		while (res.size() != nums.size()) {
			res.push_back(0);
		}
		nums = res;
	}
};