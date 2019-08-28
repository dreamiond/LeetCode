//leetcode345:Reverse Vowels of a String
/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		vector<int> dict;
		unordered_set<char> vowel{ 'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		for (int i = 0; i < s.size(); ++i) {
			if (vowel.find(s[i]) != vowel.end()) dict.push_back(i);
		}
		
		int n = dict.size()-1;
		for (int i = 0; i < (n + 1) / 2; ++i) {
			swap(s[dict[i]], s[dict[n - i]]);
		}
		return s;
	}
};

//void main() {
//	Solution sol;
//	cout<<sol.reverseVowels("hello");
//}