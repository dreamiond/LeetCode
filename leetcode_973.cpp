//leetcode973:K Closest Points to Origin
/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)



Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

//class Solution {
//public:
//	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//		multimap<int, int> m;
//		for (int i = 0; i < points.size(); ++i) {
//			m.insert(pair<int,int>{points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
//		}
//		vector<vector<int>> res;
//		multimap<int, int>::iterator it = m.begin();
//		for (int i = 0; i < K; ++i) {
//			res.push_back(points[it->second]);
//			++it;
//		}
//		return res;
//	}
//};

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<pair<int, int>> v;
		for (int i = 0; i < points.size(); ++i) {
			v.push_back(pair<int, int>{points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
		}
		quickSort(0, v.size() - 1, v);
		vector<vector<int>> res;
		for (int i = 0; i < K; ++i) {
			res.emplace_back(points[v[i].second]);
		}
		return res;
	}
	void quickSort(int begin, int end, vector<pair<int, int>> &v) {
		if (begin >= end) return;
		int mid = partition(begin, end, v);
		quickSort(begin, mid - 1, v);
		quickSort(mid + 1, end, v);
	}
	int partition(int begin, int end, vector<pair<int, int>> &v) {
		pair<int, int> tmp = v[begin];
		while (begin < end) {
			while (begin < end && v[end].first >= tmp.first) --end;
			v[begin] = v[end];
			while (begin < end && v[begin].first <= tmp.first) ++begin;
			v[end] = v[begin];
		}
		v[begin] = tmp;
		return begin;
	}
};