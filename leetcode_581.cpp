//leetcode581:Shortest Unsorted Continuous Subarray
/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
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
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> mini2n(nums.size(), 0);
		vector<int> max02i(nums.size(), 0);
		for (int i = nums.size() - 1,minimum = nums[nums.size()-1]; i >= 0; --i) {
			minimum = min(minimum, nums[i]);
			mini2n[i] = minimum;
		}
		for (int i = 0, maximum = nums[0]; i < nums.size(); ++i) {
			maximum = max(maximum, nums[i]);
			max02i[i] = maximum;
		}
		int start = 0, end = nums.size() - 1;
		while (start + 1 < nums.size() && nums[start + 1] >= nums[start] && nums[start] <= mini2n[start + 1]) ++start;
		while (end - 1 >= 0 && nums[end - 1] <= nums[end] && nums[end] >= max02i[end - 1]) --end;
		if (start >= end) return 0;
		return end - start + 1;
	}
};