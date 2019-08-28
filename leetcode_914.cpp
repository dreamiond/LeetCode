//leetcode914:X of a Kind in a Deck of Cards
/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]

Note:

1 <= deck.length <= 10000
0 <= deck[i] < 10000
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
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> dict;
		int minimum = 10001;
		for (auto i : deck) {
			++dict[i];
		}
		for (auto i : dict) {
			minimum = min(minimum, i.second);
		}
		if (minimum == 1) return false;
		for (auto i : dict) {
			if (gcd(i.second, minimum) == 1) return false;
		}
		return true;
	}
	int gcd(int a, int b) {
		int s = a < b ? a : b;
		int l = a > b ? a : b;
		int tmp = -1;
		while (s) {
			tmp = s;
			s = l%s;
			l = tmp;
		}
		return l;
	}
};
