//leetcode739:Daily Temperatures
/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> stk;
		vector<int> res(T.size(), 0);
		int n = T.size();
		for (int i = 0; i < T.size(); ++i) {
			while (!stk.empty() && T[i] > T[stk.top()]) {
				int idx = stk.top();
				stk.pop();
				res[idx] = i - idx;
			}
			stk.push(i);
		}
		return res;
	}
};