//leetcode63:Unique Paths II
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
[0,0,0],
[0,1,0],
[0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

//二维dp，斜式遍历

//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		if (obstacleGrid.empty()) return 0;
//		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//		if (obstacleGrid[m - 1][n - 1] == 1) return 0;
//		vector<vector<long long>> dp(m, vector<long long>(n, 0));
//		if (obstacleGrid[0][0] == 0) dp[0][0] = 1;
//		for (int j = 1; j < n; ++j) {
//			for (int t = 0; j - t >= 0 && t < m; ++t) {
//				//(t,j-t)
//				long long up = 0, left = 0;
//				if (t - 1 >= 0 && obstacleGrid[t - 1][j - t] == 0) {
//					up = dp[t - 1][j - t];
//				}
//				if (j - t - 1 >= 0 && obstacleGrid[t][j - t - 1] == 0) {
//					left = dp[t][j - t - 1];
//				}
//				dp[t][j - t] = up + left;
//			}
//		}
//		for (int i = 1; i < m; ++i) {
//			for (int t = 0; i + t < m && n - 1 - t >= 0; ++t) {
//				//(i+t,n-1-t)
//				long long up = 0, left = 0;
//				if (i + t - 1 >= 0 && obstacleGrid[i + t - 1][n - 1 - t] == 0) up = dp[i + t - 1][n - 1 - t];
//				if (n - 2 - t >= 0 && obstacleGrid[i + t][n - 2 - t] == 0) left = dp[i + t][n - 2 - t];
//				dp[i + t][n - 1 - t] = up + left;
//			}
//		}
//		return dp[m - 1][n - 1];
//	}
//};

//二维dp，正常做法

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] == 1) return 0;
		vector<vector<long long>> dp(m, vector<long long>(n, 0));
		if (obstacleGrid[0][0] == 0) dp[0][0] = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0) {
					dp[i][j] += dp[i - 1][j];
				}
				if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};