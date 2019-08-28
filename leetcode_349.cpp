//leetcode349:Intersection of Two Arrays
/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> usi, intersection;
		vector<int> res;
		for (auto i : nums1) {
			usi.insert(i);
		}
		for (auto i : nums2) {
			if (usi.find(i) != usi.end()) intersection.insert(i);
		}
		for (auto i : intersection) {
			res.push_back(i);
		}
		return res;
	}
};