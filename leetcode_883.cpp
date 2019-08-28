//leetcode883:Projection Area of 3D Shapes
/*
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Now we view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane.

Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.



Example 1:

Input: [[2]]
Output: 5
Example 2:

Input: [[1,2],[3,4]]
Output: 17
Explanation:
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

Example 3:

Input: [[1,0],[0,2]]
Output: 8
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 14
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 21


Note:

1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 50
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxValue(vector<int> v) {
		int res = v[0];
		for (auto i : v) {
			if (i > res) res = i;
		}
		return res;
	}

	int projectionArea(vector<vector<int>>& grid) {
		int x_value = 0, y_value = 0, z_value = 0;
		for (auto i : grid) {
			x_value += maxValue(i);
			for (auto j : i) {
				if (j != 0) z_value++;
			}
		}
		for (int i = 0; i < grid[0].size(); i++) {
			int max = 0;
			for (int j = 0; j < grid.size(); j++) {
				max = grid[j][i] > max ? grid[j][i] : max;
			}
			y_value += max;
		}
		//cout << x_value << ' ' << y_value << ' ' << z_value << endl;
		return x_value + y_value + z_value;
	}
};

//void main() {
//	vector<vector<int>> v = { {2} };
//	Solution sol;
//	cout << sol.projectionArea(v);
//}