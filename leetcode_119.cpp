//leetcode119:Pascal's Triangle II
/*
Given a non-negative index k where k �� 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 0);
		res[0] = 1;
		for (int i = 1; i < rowIndex+1; ++i) {
			for (int j = i; j > 0; --j) {
				res[j] = res[j] + res[j - 1];
			}
		}
		return res;
	}
};