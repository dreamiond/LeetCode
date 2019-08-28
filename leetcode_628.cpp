//leetcode628:Maximum Product of Three Numbers
/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < 3; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] < nums[j]) swap(nums[i], nums[j]);
			}
		}
		for (int i = n - 1; i > n - 3; --i) {
			for (int j = i - 1; j > 0; --j) {
				if (nums[i] > nums[j]) swap(nums[i], nums[j]);
			}
		}
		return nums[0] * max(nums[1] * nums[2], nums[n - 1] * nums[n - 2]);
	}
};