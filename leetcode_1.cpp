//leetcode1:Two Sum
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
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
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> dict;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			if (dict.find(target - nums[i]) != dict.end()) {
				res.push_back(dict[target - nums[i]]);
				res.push_back(i);
				return res;
			}
			dict[nums[i]] = i;
		}
		return res;
	}
};