//leetcode238:Product of Array Except Self
/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 0);
		for (int i = 0, left = 1; i < nums.size(); ++i) {
			res[i] = left;
			left *= nums[i];
		}
		for (int i = nums.size() - 1, right = 1; i >= 0; --i) {
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
};