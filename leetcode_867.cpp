//leetcode867:Transpose Matrix
/*
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.



Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]


Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int row = A.size(), column = A[0].size();
		vector<vector<int>> v;
		for (int i = 0; i < column; i++) {
			vector<int> temp;
			for (int j = 0; j < row; j++) {
				temp.push_back(A[j][i]);
			}
			v.push_back(temp);
		}
		A = v;
		return A;
	}
};

//void main() {
//	vector<vector<int>> v = { {1,2,3},{4,5,6},{7,8,9} };
//	Solution sol;
//	v = sol.transpose(v);
//	for (auto i : v) {
//		for (auto j : i) {
//			cout << j << ' ';
//		}
//		cout << endl;
//	}
//}