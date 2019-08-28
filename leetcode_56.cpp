//leetcode56:Merge Intervals
/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) return vector<vector<int>>{};
		map<int, int> numOfPersonGetOnTheCar{}; //map�ᰴ��index��С����ά����ϣ��
		for (const auto &iv : intervals) {
			//iv����ÿһ�����䣬[x,y]��ʽ
			//��xλ���ϳ�һ�ˣ���yλ���³�һ��
			++numOfPersonGetOnTheCar[iv[0]];
			--numOfPersonGetOnTheCar[iv[1]];
		}
	
		vector<vector<int>> res;
		int start = intervals[0][0], num = 0; //��ʼ����û����
		for (const auto &it : numOfPersonGetOnTheCar) {
			if (num == 0) start = it.first;
			num += it.second;
			if (num == 0) {
				res.emplace_back(vector<int>{start, it.first});
			}
		}
		return res;
	}
};