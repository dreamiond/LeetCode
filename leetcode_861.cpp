//leetcode861:Score After Flipping Matrix
/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.



Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39


Note:

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.
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
	int matrixScore(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); ++i) {
			if (A[i][0] == 0) revLine(A, i);
		}
		for (int j = 0; j < A[0].size(); ++j) {
			int numOf0 = 0;
			for (int i = 0; i < A.size(); ++i) {
				if (A[i][j] == 0) ++numOf0;
			}
			if (numOf0 > A.size() / 2) {
				revCol(A, j);
			}
		}
		int res = 0;
		for (auto v : A) {
			res += vec2Num(v);
		}
		return res;
	}
	void revLine(vector<vector<int>>& A, int i) {
		for (int j = 0; j < A[i].size(); ++j) {
			A[i][j] = (A[i][j] == 0) ? 1 : 0;
		}
	}
	void revCol(vector<vector<int>>& A, int j) {
		for (int i = 0; i < A.size(); ++i) {
			A[i][j] = (A[i][j] == 0) ? 1 : 0;
		}
	}
	int vec2Num(vector<int> v) {
		int res = 0;
		for (int i = v.size() - 1, k = 1; i >= 0; --i, k *= 2) {
			res += v[i] * k;
		}
		return res;
	}
};