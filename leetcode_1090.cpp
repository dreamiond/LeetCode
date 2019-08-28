//leetcode1090:Largest Values From Labels
/*
We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.



Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.
Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.
Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.
Example 4:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
Output: 24
Explanation: The subset chosen is the first, second, and fourth item.


Note:

1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i] <= 20000
1 <= num_wanted, use_limit <= values.length
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <xfunctional>
#include <unordered_map>

using namespace std;


// π”√multimap≈≈–Ú

class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		if (values.size() == 0) return 0;
		multimap<int, int, greater<int>> v2l{};
		int n = values.size();
		for (int i = 0; i < n; ++i) {
			v2l.insert({ values[i],labels[i] });
		}
		
		unordered_map<int, int> useTime{};
		int res = 0, num = 0;
		for (const auto &p : v2l) {
			if (useTime[p.second] < use_limit) {
				++useTime[p.second];
				++num;
				res += p.first;
			}
			if (num == num_wanted) {
				break;
			}
		}
		return res;
	}
};

class Solution {
public:
	struct Node {
		int val, lab;
		Node() {};
		Node(int x, int y) {
			val = x, lab = y;
		}
		bool operator < (const Node &rhs) const {
			return val>rhs.val;
		}
	};
	int cnt[20005];
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<Node> res;
		int len = values.size();
		for (int i = 0; i<len; i++) {
			res.push_back(Node(values[i], labels[i]));
		}
		sort(res.begin(), res.end());
		memset(cnt, 0, sizeof(cnt));
		int num = 0;
		int ans = 0;
		for (int i = 0; i<len; i++) {
			if (num == num_wanted)
				break;
			if (cnt[res[i].lab] >= use_limit)
				continue;
			ans += res[i].val;
			cnt[res[i].lab]++;
			num++;
		}
		return ans;
	}
};