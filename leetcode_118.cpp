//leetcode118:Pascal's Triangle
/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows == 0) return res;
		res.push_back(vector<int>{1});
		if (numRows == 1) return res;
		for (int i = 1; i < numRows; ++i) {
			vector<int> tmp;
			for (int j = 0; j <= i; ++j) {
				int num = 0;
				if (j - 1 >= 0) num += res[i - 1][j - 1];
				if (j < i) num += res[i - 1][j];
				tmp.push_back(num);
			}
			res.push_back(tmp);
		}
		return res;
	}
};