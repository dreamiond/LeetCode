//leetcode959:Regions Cut By Slashes
/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.



Example 1:

Input:
[
" /",
"/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
" /",
"  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
"\\/",
"/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
"/\\",
"\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
"//",
"/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:



Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

//并查集做法

//class Solution {
//private:
//	int count, n;
//	vector<int> f;
//public:
//	int regionsBySlashes(vector<string>& grid) {
//		n = grid.size();
//		count = n*n * 4;
//		for (int i = 0; i < count; ++i) f.push_back(i);
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
//				if (j > 0) uni(g(i, j - 1, 1), g(i, j, 3));
//				if (grid[i][j] != '/') {
//					uni(g(i, j, 0), g(i, j, 1));
//					uni(g(i, j, 2), g(i, j, 3));
//				}
//				if (grid[i][j] != '\\') {
//					uni(g(i, j, 0), g(i, j, 3));
//					uni(g(i, j, 1), g(i, j, 2));
//				}
//			}
//		}
//		return count;
//	}
//
//	int father(int x) {
//		int root = x;
//		while (x != f[x]) {
//			x = f[x];
//		}
//		while (root != x) {
//			int tmp = f[root];
//			f[root] = x;
//			root = tmp;
//		}
//		return x;
//	}
//	
//	void uni(int x, int y) {
//		x = father(x);
//		y = father(y);
//		if (x != y) {
//			f[x] = y;
//			count--;
//		}
//	}
//
//	int g(int x, int y, int k) {
//		return (x*n + y) * 4 + k;
//	}
//};

//DFS

class Solution {
public:
	int regionsBySlashes(vector<string>& grid) {
		int count = 0;
		int n = grid.size();
		int m = n * 3;
		vector<vector<int>> g(m, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '/') {
					//对角线置一
					g[i * 3][j * 3 + 2] = 1;
					g[i * 3 + 1][j * 3 + 1] = 1;
					g[i * 3 + 2][j * 3] = 1;
				}
				if (grid[i][j] == '\\') {
					//对角线置一
					g[i * 3][j * 3] = 1;
					g[i * 3 + 1][j * 3 + 1] = 1;
					g[i * 3 + 2][j * 3 + 2] = 1;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == 0) {
					dfs(g, i, j);
					++count;
				}
			}
		}
		return count;
	}

	void dfs(vector<vector<int>> &g, int i, int j) {
		if (i < g.size() && j < g.size() && i >= 0 && j >= 0 && g[i][j] == 0) {
			g[i][j] = 1;
			dfs(g, i - 1, j);
			dfs(g, i + 1, j);
			dfs(g, i, j - 1);
			dfs(g, i, j + 1);
		}
	}
};