//leetcode38:Count and Say
/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
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
	string countAndSay(int n) {
		string res = "1";
		for (int i = 1; i < n; ++i) {
			res = cas(res);
		}
		return res;
	}
	string cas(string s) {
		string res = "";
		int i = 0, j = 0;
		for (; i < s.size(); ++i) {
			for (j = i + 1; j < s.size(); ++j) {
				if (s[i] != s[j]) {
					res = res + to_string(j - i) + s[i];
					i = j;
				}
			}
			if (j == s.size()) break;
		}
		res = res + to_string(j - i) + s[i];
		return res;
	}
};