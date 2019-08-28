//leetcode980:Unique Paths III
/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation:
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.


Note:

1 <= grid.length * grid[0].length <= 20
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int dfs(vector<vector<int>>& grid, int i, int j, int path, int num) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) return 0;
		if (grid[i][j] == 2) return path == num ? 1 : 0;
		grid[i][j] = -1;
		int res = dfs(grid, i + 1, j, path + 1, num) + dfs(grid, i - 1, j, path + 1, num)
				+ dfs(grid, i, j + 1, path + 1, num) + dfs(grid, i, j - 1, path + 1, num);
		grid[i][j] = 0;
		return res;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int x = 0, y = 0, num = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) x = i, y = j;
				if (grid[i][j] != -1) ++num;
			}
		}
		return dfs(grid, x, y, 1, num);
	}
};