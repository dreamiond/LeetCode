//leetcode46:Permutations
/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
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
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> used(nums.size(), 0);
		helper(nums, vector<int>{}, res);
		return res;
	}
	void helper(const vector<int> &nums, vector<int> construct, vector<vector<int>> &res) {
		for (const auto &num:nums) {
			if (construct.size() == nums.size()) {
				res.emplace_back(construct);
				return;
			}
			else {
				if (find(construct.begin(), construct.end(), num) == construct.end()) {
					construct.push_back(num);
					helper(nums, construct, res);
					construct.pop_back();
				}
			}
		}
	}
};

//int main() {
//	vector<int> nums{ 1,2,3 };
//	Solution sol;
//	vector<vector<int>> res = sol.permute(nums);
//}