//leetcode1043:Partition Array for Maximum Sum
/*
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.



Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]


Note:

1 <= K <= A.length <= 500
0 <= A[i] <= 10^6
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
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		int N = A.size();
		vector<int> dp(N);
		for (int i = 0; i < N; ++i) {
			int curMax = 0;
			for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
				curMax = max(curMax, A[i - k + 1]);
				dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
			}
		}
		return dp[N - 1];
	}
};