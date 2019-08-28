//leetcode849:Maximize Distance to Closest Person
/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

//class Solution {
//public:
//	int maxDistToClosest(vector<int>& seats) {
//		int *left = new int[seats.size()];
//		for (int i = 0, lastOne = -seats.size(); i < seats.size(); ++i) {
//			if (seats[i] == 1) {
//				lastOne = i;
//				left[i] = -1;
//				continue;
//			}
//			else {
//				left[i] = i - lastOne;
//			}
//		}
//		int maximum = 0;
//		for (int i = seats.size()-1,lastOne = INT_MAX; i >= 0; --i) {
//			if (seats[i] == 1) {
//				lastOne = i;
//				continue;
//			}
//			else {
//				maximum = max(maximum, min(left[i], lastOne - i));
//			}
//		}
//		return maximum;
//	}
//};

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int maxLength = 0, i = 0, count = 0, left = 0;
		for (i = 0; i < seats.size(); ++i) {
			if (seats[i] == 1) break;
			++left;
		}
		for (; i < seats.size(); ++i) {
			if (seats[i] == 0) {
				++count;
			}
			else {
				maxLength = max(count, maxLength);
				count = 0;
			}
		}
		int res  = max(left, count);
		return max(res, (maxLength + 1) / 2);
	}
};