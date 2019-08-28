//leetcode347:Top K Frequent Elements
/*

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> num2time;
		for (auto i : nums) {
			++num2time[i];
		}
		vector<vector<int>> time2num(nums.size() + 1, vector<int>());
		int biggestTime = 0;
		for (auto nt : num2time) {
			time2num[nt.second].emplace_back(nt.first);
			biggestTime = max(biggestTime, nt.second);
		}
		vector<int> res;
		for (int i = biggestTime; k; --i) {
			if (!time2num[i].empty()) {
				for (auto j : time2num[i]) {
					res.push_back(j);
					--k;
				}
			}
		}
		return res;
	}
};