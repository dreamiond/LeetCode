//leetcode442:Find All Duplicates in an Array
/*
Given an array of integers, 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

//class Solution {
//public:
//	vector<int> findDuplicates(vector<int>& nums) {
//		vector<int> res;
//		nums.push_back(0);
//		for (int i = 0; i < nums.size(); ) {
//			if (nums[i] != nums[nums[i]]) swap(nums[i], nums[nums[i]]);
//			else ++i;
//		}
//		for (int i = 0; i < nums.size(); ++i) {
//			if (nums[i] != i) res.push_back(nums[i]);
//		}
//		return res;
//	}
//};

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
			else res.emplace_back(abs(nums[i]));
		}
		return res;
	}
};