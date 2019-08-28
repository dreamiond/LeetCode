//leetcode754:Reach a Number
/*
You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <queue>

using namespace std;

//class Solution {
//public:
//	int reachNumber(int target) {
//		unordered_map<int, int> dis;
//		dis[0] = 0;
//		queue<int> q;
//		q.push(0);
//		while (dis.find(target) == dis.end()) {
//			int tmp = q.front();
//			dis[tmp + dis[tmp] + 1] = dis[tmp] + 1;
//			dis[tmp - dis[tmp] - 1] = dis[tmp] + 1;
//			q.push(tmp - dis[tmp] - 1);
//			q.push(tmp + dis[tmp] + 1);
//			q.pop();
//		}
//		return dis[target];
//	}
//};

/*
We can always take abs(target), since the axis is symmetric.

First of all we keep adding sum=1+2+..+n>=target, solve this quadratic equation gives the smallest n such that sum>=target.

If 1+2+..+n==target, return n.

Now we must minus res=sum-target. If res is even, we can flip one number x in [1,n] to be -x.

Otherwise if res is odd, and n+1 is odd, we can first add n+1, then res is even. Next flip an x to be -x.

If res is odd and n+1 is even, we add n+1 then subtract n+2, res becomes even, then flip an x.
*/

//class Solution {
//public:
//	int reachNumber(int target) {
//		int sum = 0, n = 0;
//		if (target < 0) target = -target;
//		while (sum < target) {
//			++n;
//			sum += n;
//		}
//		if (sum == target) return n;
//		int res = sum - target;
//		if (res % 2 == 0) return n;
//		else {
//			if ((n + 1) % 2 == 1) return n + 1;
//			else return n + 2;
//		}
//	}
//};

//void main() {
//	Solution sol;
//	cout << sol.reachNumber(2) << endl;
//}
