//leetcode746:Min Cost Climbing Stairs
/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		/*��̬�滮��
		f(n) = min{[f(n-1)+cost(n-1)],[f(n-2)+cost[n-2]]}
		f(0) = f(1) = 0
		*/
		int n = cost.size();
		vector<int> fn(n+1, 0);
		for (int i = 2; i < n+1; ++i) {
			fn[i] = min(fn[i - 1] + cost[i - 1], fn[i - 2] + cost[i - 2]);
		}
		return fn[n];
	}
};