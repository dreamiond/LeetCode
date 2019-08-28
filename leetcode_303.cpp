//leetcode303:Range Sum Query - Immutable
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

class NumArray {
private:
	int *f;
public:
	NumArray(vector<int> nums) {
		f = new int[nums.size()];
		for (int i = 0,sum = 0; i < nums.size(); ++i) {
			sum += nums[i];
			f[i] = sum;
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) return f[j];
		return f[j] - f[i - 1];
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/