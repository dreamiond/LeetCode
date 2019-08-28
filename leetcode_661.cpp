//leetcode661:Image Smoother
/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
[1,0,1],
[1,1,1]]
Output:
[[0, 0, 0],
[0, 0, 0],
[0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));
		for (int i = 0; i < M.size(); ++i) {
			for (int j = 0; j < M[0].size(); ++j) {
				int sum = M[i][j], num = 1;
				//左上
				if (i - 1 >= 0 && j - 1 >= 0) {
					sum += M[i - 1][j - 1];
					++num;
				}
				//中上
				if (i - 1 >= 0) {
					sum += M[i - 1][j];
					++num;
				}
				//右上
				if (i - 1 >= 0 && j + 1 < M[0].size()) {
					sum += M[i - 1][j + 1];
					++num;
				}
				//左中
				if (j - 1 >= 0) {
					sum += M[i][j - 1];
					++num;
				}
				//右中
				if (j + 1 < M[0].size()) {
					sum += M[i][j + 1];
					++num;
				}
				//左下
				if (i + 1 < M.size() && j - 1 >= 0) {
					sum += M[i + 1][j - 1];
					++num;
				}
				//中下
				if (i + 1 < M.size()) {
					sum += M[i + 1][j];
					++num;
				}
				//右下
				if (i + 1 < M.size() && j + 1 < M[0].size()) {
					sum += M[i + 1][j + 1];
					++num;
				}
				res[i][j] = sum / num;
			}
		}
		return res;
	}
};