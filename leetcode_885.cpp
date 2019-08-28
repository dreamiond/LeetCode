//leetcode885:Spiral Matrix III
/*
On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid.

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.



Example 1:

Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]




Example 2:

Input: R = 5, C = 6, r0 = 1, c0 = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]




Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
private:
	const int EAST = 0;
	const int SOUTH = 1;
	const int WEST = 2;
	const int NORTH = 3;
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> res{ vector<int>{r0,c0} };
		vector<int> pos{ r0,c0 };
		int face = EAST;
		int length = 1;
		int height = max(r0, R - r0 - 1);
		int width = max(c0, C - c0 - 1);
		while (abs(pos[0] - r0) <= height || abs(pos[1] - c0) <= width) {
			pos = go(pos, length, face, res, R, C);
			face = (face + 1) % 4;
			pos = go(pos, length, face, res, R, C);
			face = (face + 1) % 4;
			++length;
		}
		return res;
	}
	vector<int> go(vector<int> start, int length, int face, vector<vector<int>> &res, int R, int C) {
		if (face == EAST) {
			for (int i = 0; i < length; ++i) {
				++start[1];
				if (start[0] >= 0 && start[0] < R && start[1] >= 0 && start[1] < C) res.push_back(start);
			}
		}
		else if (face == SOUTH) {
			for (int i = 0; i < length; ++i) {
				++start[0];
				if (start[0] >= 0 && start[0] < R && start[1] >= 0 && start[1] < C) res.push_back(start);
			}
		}
		else if (face == WEST) {
			for (int i = 0; i < length; ++i) {
				--start[1];
				if (start[0] >= 0 && start[0] < R && start[1] >= 0 && start[1] < C) res.push_back(start);
			}
		}
		else {
			for (int i = 0; i < length; ++i) {
				--start[0];
				if (start[0] >= 0 && start[0] < R && start[1] >= 0 && start[1] < C) res.push_back(start);
			}
		}
		return start;
	}
};