//leetcode797:All Paths From Source to Target
/*
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
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
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> res;
		helper(graph, res, 0);
		return res;
	}
	void helper(vector<vector<int>> &graph, vector<vector<int>> &res, int cur, vector<int> path = {}) {
		if (cur == graph.size()) return;
		path.push_back(cur);
		if (cur == graph.size() - 1) {
			res.push_back(path);
			return;
		}
		for (auto node : graph[cur]) {
			helper(graph, res, node, path);
		}
	}
};