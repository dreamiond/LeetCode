//leetcode414:Third Maximum Number
/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
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
	int thirdMax(vector<int>& nums) {
		unordered_set<int> us;
		for (auto i : nums) us.insert(i);
		vector<int> v{ INT_MIN ,INT_MIN ,INT_MIN };
		for (auto i : us) vInsert(v, i);
		if (us.size() < 3) return v[0];
		return v[2];
	}
	void vInsert(vector<int> &v, int n) {
		int pos = 0;
		while (pos < 3 && v[pos] >= n) ++pos;
		if (pos != 3) {
			int tmp = v[pos];
			v[pos] = n;
			vInsert(v, tmp);
		}
	}
};