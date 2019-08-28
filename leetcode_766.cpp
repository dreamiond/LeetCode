//leetcode766:Toeplitz Matrix
/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


Example 1:

Input:
matrix = [
[1,2,3,4],
[5,1,2,3],
[9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:

Input:
matrix = [
[1,2],
[2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		for (int x = 0; x < matrix.size(); ++x) {
			if (!diagonalSame(matrix, x, 0)) return false;
		}
		for (int y = 1; y < matrix[0].size(); ++y) {
			if (!diagonalSame(matrix, 0, y)) return false;
		}
		return true;
	}
	bool diagonalSame(const vector<vector<int>>& matrix,int x,int y) {
		//cout << "第" << x << "行" << "第" << y << "列" << endl;
		int x_size = matrix.size(), y_size = matrix[0].size();
		int num = matrix[x][y];
		while (x < x_size&&y < y_size) {
			if (matrix[x][y] != num) {
				//cout << "false" << endl;
				return false;
			}
			x++; y++;
		}
		//cout << "true" << endl;
		return true;
	}
};

//void main() {
//	vector<vector<int>> v = { {11, 74, 0, 93},{40, 11, 74, 7} };
//	Solution sol;
//	sol.isToeplitzMatrix(v);
//}