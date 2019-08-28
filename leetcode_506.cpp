//leetcode506:Relative Ranks
/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <xfunctional>

using namespace std;

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		map<int, int,greater<int>> dict;
		for (int i = 0; i < nums.size(); ++i) {
			dict[nums[i]] = i;
		}
		vector<string> res(nums.size(), "");
		auto it = dict.begin();
		res[it->second] = "Gold Medal";
		++it;
		if (it == dict.end()) return res;
		res[it->second] = "Silver Medal";
		++it;
		if (it == dict.end()) return res;
		res[it->second] = "Bronze Medal";
		++it;
		if (it == dict.end()) return res;
		int index = 3;
		while (it != dict.end()) {
			res[it->second] = to_string(++index);
			++it;
		}
		return res;
	}
};