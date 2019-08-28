//leetcode674:Longest Continuous Increasing Subsequence
/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
Note: Length of the array will not exceed 10,000.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		//其实也还是动归。这个故事告诉我们，动归的函数不一定是目标函数。
		if (nums.size() == 0) return 0;
		int res = 1, count = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] <= nums[i - 1]) count = 1;
			else ++count;
			res = max(res, count);
		}
		return res;
	}
};