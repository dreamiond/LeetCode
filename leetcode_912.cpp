//leetcode912:Sort an Array
/*
Given an array of integers nums, sort the array in ascending order.



Example 1:

Input: [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]


Note:

1 <= A.length <= 10000
-50000 <= A[i] <= 50000
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
	vector<int> sortArray(vector<int>& nums) {
		quickSort(nums, 0, nums.size() - 1);
		return nums;
	}

	void quickSort(vector<int> &nums, int low, int high) {
		if (low >= high) return;
		int mid = partition(nums, low, high);
		quickSort(nums, low, mid - 1);
		quickSort(nums, mid + 1, high);
	}

	int partition(vector<int> &nums, int start, int end) {
		int tmp = nums[start];
		while (start < end) {
			while (start < end && nums[end] >= tmp) --end;
			nums[start] = nums[end];
			while (start < end && nums[start] <= tmp) ++start;
			nums[end] = nums[start];
		}
		nums[start] = tmp;
		return start;
	}
};