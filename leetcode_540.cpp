//leetcode540:Single Element in a Sorted Array
/*
Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once. Find this single element that appears only once.



Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10


Note: Your solution should run in O(log n) time and O(1) space.


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
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];

		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = (right - left) / 2 + left;
			if (mid !=0 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
			if (mid % 2 == 0) {
				//与右同则目标在右，与左同则目标在左
				if (nums[mid] == nums[mid + 1]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			else {
				//与左同则目标在右，与右同则目标在左
				if (nums[mid] == nums[mid + 1]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		return nums[left];
	}
};