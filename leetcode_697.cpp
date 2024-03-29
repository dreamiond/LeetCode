//leetcode697:Degree of an Array
/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	int findShortestSubArray(vector<int>& nums) {
//		unordered_map<int, int> dict;
//		int res = nums.size();
//		int maxFrequency = 0;
//		for (auto i : nums) {
//			++dict[i];
//			maxFrequency = max(maxFrequency, dict[i]);
//		}
//		vector<int> numsHaveMaxFrequency;
//		for (auto i : nums) {
//			if (dict[i] == maxFrequency) {
//				numsHaveMaxFrequency.push_back(i);
//			}
//		}
//		for (auto num : numsHaveMaxFrequency) {
//			int low = nums.size() - 1, high = 0;
//			for (int i = 0; i < nums.size(); ++i) {
//				if (nums[i] == num) {
//					low = min(low, i);
//					high = max(high, i);
//				}
//			}
//			res = min(res, high - low + 1);
//		}
//		return res;
//	}
//};

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i<nums.size(); i++) mp[nums[i]].push_back(i);
		int degree = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) degree = max(degree, int(it->second.size()));
		int shortest = nums.size();
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second.size() == degree)
			{
				shortest = min(shortest, it->second.back() - it->second[0] + 1);
			}
		}
		return shortest;
	}
};

//void main() {
//	vector<int> v = { 1,2,2,3,1 };
//	Solution sol;
//	sol.findShortestSubArray(v);
// }