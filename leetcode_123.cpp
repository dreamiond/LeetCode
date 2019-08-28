//leetcode123:Best Time to Buy and Sell Stock III
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//两次动归，f(i)代表从0到i的最大利润，g(i)代表从i到n-1的最大利润
		int n = prices.size();
		if (n <= 1) return 0;
		int *f = new int[n], *g = new int[n];

		//f(i) = max(f(i-1),prices(i)-min(0到n-1的价格))
		int minimum = prices[0];
		f[0]=0;
		for (int i = 1; i < prices.size(); ++i) {
			f[i] = max(f[i - 1], prices[i] - minimum);
			minimum = min(minimum, prices[i]);
		}

		//g(i) = max(g(i+1),max(i+1到n-1的价格)-prices(i))
		int maximum = prices[n - 1];
		g[n - 1] = 0;
		for (int i = n - 2; i >= 0; --i) {
			g[i] = max(g[i + 1], maximum-prices[i]);
			maximum = max(maximum, prices[i]);
		}
		//for (int i = 0; i < n; ++i) cout << f[i] << " ";
		//cout << endl;
		//for (int i = 0; i < n; ++i) cout << g[i] << " ";
		//最大利润为max(f(i)+g(i)),i从0到n-1
		int res = 0;
		for (int i = 0; i < n; ++i) {
			res = max(res, f[i] + g[i]);
		}
		return res;
	}
};

//void main() {
//	vector<int> v = { 3,3,5,0,0,3,1,4 };
//	Solution sol;
//	sol.maxProfit(v);
//}