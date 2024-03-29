//leetcode458:Poor Pigs
/*
There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
//		int base = minutesToTest / minutesToDie + 1;
//		int res = ceil(log(buckets) / log(base));
//		return res;
//	}
//};