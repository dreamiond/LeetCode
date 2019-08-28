//leetcode743:Network Delay Time
/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
private:
	const int MAX_TIME = 6001;
	vector<vector<int>> edge;
	int shortestVertex(vector<int> tmp, vector<int> dis) {
		//使用前检查是否tmp是空数组
		int res = tmp[0];
		for (int i = 0; i < tmp.size(); ++i) {
			res = dis[tmp[i]] < dis[res] ? tmp[i] : res;
		}
		return res;
	}
	void constructEdge(vector<vector<int>>& times, int N) {
		edge = vector<vector<int>>(N, vector<int>(N, MAX_TIME));
		for (int i = 0; i < N; ++i) {
			edge[i][i] = 0;
		}
		for (auto v : times) {
			edge[v[0] - 1][v[1] - 1] = v[2];
		}
		printEdge();
	}
	void printEdge() {
		for (auto v : edge) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
	void printDis(vector<int> dis) {
		for (auto i : dis) cout << i << " ";
		cout << endl;
	}

public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		K = K - 1;
		vector<int> dis(N, MAX_TIME);
		unordered_set<int> scannedVertex;
		int currentVertex = K;
		constructEdge(times, N);
		dis[K] = 0;
		while (scannedVertex.size() != N) {
			scannedVertex.insert(currentVertex);
			vector<int> tmp;
			for (int i = 0; i < N; ++i) {
				//如果i顶点还未被扫描,即i节点不在scannedVertex数组中
				if (scannedVertex.find(i) == scannedVertex.end()) {
					dis[i] = min(dis[i], dis[currentVertex] + edge[currentVertex][i]);
					tmp.push_back(i);
				}
			}
			if (!tmp.empty()) currentVertex = shortestVertex(tmp, dis);
			
			printDis(dis);
		}

		int res = 0;
		for (auto i : dis) {
				res = i > res ? i : res;
		}
		if(res == MAX_TIME) return -1;
		return res;
	}
	
};

//void main() {
//	Solution sol;
//	vector<vector<int>> times = { {1,2,1},{2,3,2},{1,3,1} };
//	sol.networkDelayTime(times, 3, 2);
//}