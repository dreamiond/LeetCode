//leetcode1074:Number of Submatrices That Sum to Target
/*
Given a matrix, and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.



Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.


Note:

1 <= matrix.length <= 300
1 <= matrix[0].length <= 300
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
		if (A.empty() || A[0].empty()) return 0;
		int m = A.size(), n = A[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				A[i][j] += A[i][j - 1];
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				unordered_map<int, int> counter;
				int cur = 0;
				counter[0] = 1;
				for (int k = 0; k < m; ++k) {
					cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
					res += counter[cur - target];
					++counter[cur];
				}
			}
		}
		return res;
	}
};