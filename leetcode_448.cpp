//leetcode448:Find All Numbers Disappeared in an Array
/*
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
				--i;
			}
		}
		for (int i = 0; i < nums.size(); ++i) {
			cout << nums[i] << endl;
			if (nums[i] != i + 1) res.push_back(i + 1);
		}
		return res;
	}
};

//void main() {
//	vector<int> v = { 4,3,2,7,8,2,3,1 };
//	Solution sol;
//	sol.findDisappearedNumbers(v);
//}