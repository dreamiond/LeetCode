//leetcode475:Heaters
/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.


Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.


Example 2:

Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be w
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
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		vector<int> leftDis(houses.size(), INT_MAX), rightDis(houses.size(), INT_MAX);
		for (int i = houses.size() - 1, j = heaters.size() - 1; i >= 0 & j >= 0;) {
			if (houses[i] >= heaters[j]) { leftDis[i] = houses[i] - heaters[j]; --i;}
			else { --j; }
		}
		for (int i = 0, j = 0; i < houses.size() && j < heaters.size();) {
			if (houses[i] <= heaters[j]) { rightDis[i] = heaters[j] - houses[i]; ++i;}
			else { ++j; }
		}
		for (int i = 0; i < leftDis.size(); ++i) {
			leftDis[i] = min(leftDis[i], rightDis[i]);
		}
		int res = 0;
		for (auto i : leftDis) res = max(res, i);
		return res;
	}
};