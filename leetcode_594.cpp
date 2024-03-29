//leetcode594:Longest Harmonious Subsequence
/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int> dict;
		for (auto i : nums) ++dict[i];
		int res = 0;
		for (auto it : dict) {
			if (dict.find(it.first - 1)!=dict.end()) {
				res = max(res, it.second + dict[it.first - 1]);
			}
		}
		return res;
	}
};