//leetcode169:Majority Element
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = 0;
		for (int i = 0,mask = 1; i < 32; ++i, mask <<= 1) {
			int bitcount = 0;
			for (int j = 0; j < nums.size(); ++j) {
				if (nums[j] & mask) ++bitcount;
				if (bitcount > nums.size() / 2) {
					res |= mask;
					break;
				}
			}
		}
		return res;
	}
};