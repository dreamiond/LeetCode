//leetcode812:Largest Triangle Area    
/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation:
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
-50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	double largestTriangleArea(vector<vector<int>>& points) {
		double maximum = 0.0;
		for (int i = 0; i < points.size(); ++i) {
			for (int j = i + 1; j < points.size(); ++j) {
				for (int k = j + 1; k < points.size(); ++k) {
					//cout << "maximum:" << maximum << endl;
					//cout << triangleArea(points[i], points[j], points[k]) << endl;
					maximum = max(triangleArea(points[i], points[j], points[k]), maximum);
				}
			}
		}
		return maximum;
	}
	double triangleArea(vector<int> a,vector<int> b,vector<int> c) {
		int ax = a[0], ay = a[1], bx = b[0], by = b[1], cx = c[0], cy = c[1];
		double res = fabs(ax*by + ay*cx + bx*cy - ax*cy - by*cx - ay*bx)/2;
		return res;
	}
};

//int main() {
//	vector<vector<int>> v = { {1,0},{0,0},{0,1} };
//	Solution sol;
//	sol.largestTriangleArea(v);
//}