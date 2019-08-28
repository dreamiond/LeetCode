//leetcode447:Number of Boomerangs
/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int booms = 0;
		for (auto &p : points) {
			unordered_map<double, int> dict(points.size());
			for (auto &q : points) {
				double distance = hypot(p.first - q.first, p.second - q.second);
				booms += 2*dict[distance];
				++dict[distance];
			}
		}
		return booms;
	}
};

//void main() {
//	vector<pair<int, int>> points = { {0,0},{1,0},{-1,0},{0,1},{0,-1} };
//	Solution sol;
//	sol.numberOfBoomerangs(points);
//}