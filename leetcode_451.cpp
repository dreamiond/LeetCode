//leetcode451:Sort Characters By Frequency
/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <math.h>
#include <xfunctional>

using namespace std;

//用stl的sort进行排序，效率较低

//class Solution {
//public:
//	string frequencySort(string s) {
//		unordered_map<char, int> dict;
//		for (auto c : s) ++dict[c];
//		sort(s.begin(), s.end(), [&](char a, char b) {
//			return dict[a] > dict[b] || (dict[a] == dict[b] && a < b); 
//		});
//		return s;
//	}
//};


//用stl的map进行排序，效率更高

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> charCounter;
		for (auto c : s) ++charCounter[c];
		multimap<int, char,greater<int>> sorter;
		for (auto i : charCounter) sorter.emplace(pair<int, char>{i.second, i.first});
		string res = "";
		for (auto i : sorter) {
			res += string(i.first, i.second);
		}
		return res;
	}
};