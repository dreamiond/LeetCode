//leetcode406:Queue Reconstruction by Height
/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), greaterHelper);
		vector<vector<int>> res;
		for (auto v : people) {
			res.insert(res.begin()+v[1], v);
		}
		return res;
	}
	static bool greaterHelper(vector<int> a,vector<int> b) {
		if (a[0] > b[0]) return true;
		else if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		else return false;
	}
};

//int main() {
//	vector<vector<int>> people{ {8,2},{4,2},{4,5},{2,0},{7,2},{1,4},{ 9,1 },{ 3,1 },{ 9,0 },{ 1,0 } };
//	Solution sol;
//	sol.reconstructQueue(people);
//}