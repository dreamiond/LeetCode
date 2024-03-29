//leetcode453:Minimum Moves to Equal Array Elements
/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int minimum = nums[0];
		for (auto i : nums) {
			minimum = min(i, minimum);
		}
		int res = 0;
		for (auto i : nums) {
			res += (i - minimum);
		}
		return res;
	}
};