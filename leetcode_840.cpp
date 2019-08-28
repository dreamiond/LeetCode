//leetcode840:Magic Squares In Grid
/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).



Example 1:

Input: [[4,3,8,4],
[9,5,1,9],
[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
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
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		if (grid.empty()) return true;
		int xSize = grid.size(), ySize = grid[0].size();
		int res = 0;
		for (int i = 0; i + 2 < xSize; ++i) {
			for (int j = 0; j + 2 < ySize; ++j) {
				if (isMagic(grid, i, j)) ++res;
			}
		}
		return res;
	}
	
	bool isMagic(vector<vector<int>>& grid, int x, int y) {
		vector<int> numDict(10,0);
		for (int i = x; i < x + 3; ++i) {
			for (int j = y; j < y + 3; ++j) {
				if (grid[i][j] > 9 || grid[i][j] < 1) return false;
				if (numDict[grid[i][j]] != 0) return false;
				++numDict[grid[i][j]];
			}
		}
		int num = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
		for (int i = x; i < x + 3; ++i) {
			int tmp = 0;
			for (int j = y; j < y + 3; ++j) tmp += grid[i][j];
			if (tmp != num) return false;
		}
		for (int j = y; j < y + 3; ++j) {
			int tmp = 0;
			for (int i = x; i < x + 3; ++i) tmp += grid[i][j];
			if (tmp != num) return false;
		}
		if ((grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2]) != num) return false;
		if ((grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2]) != num) return false;
		return true;
	}
};