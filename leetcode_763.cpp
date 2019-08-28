//leetcode763:Partition Labels
/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

//class Solution {
//private:
//	struct partition{
//		int start, end;
//		unordered_set<char> dict;
//	};
//public:
//	vector<int> partitionLabels(string S) {
//		vector<int> res;
//		vector<partition> v;
//		for (int i = 0; i < S.size(); ++i) {
//
//		}
//	}
//};

class Solution {
public:
	vector<int> partitionLabels(string S) {
		unordered_map<char, int> dict;
		for (int i = 0; i < S.size(); ++i) {
			dict[S[i]] = i;
		}
		vector<int> res;
		int maxIdx = -1, lastIdx = 0;
		for (int i = 0; i < S.size(); ++i) {
			maxIdx = max(maxIdx, dict[S[i]]);
			if (i == maxIdx) {
				res.push_back(i - lastIdx + 1);
				lastIdx = i + 1;
			}
		}
		return res;
	}
};