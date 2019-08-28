//leetcode709:To Lower Case
/*
Implement function ToLowerCase() that has a string parameter str, 
and returns the same string in lowercase.
Example 1:
Input: "Hello"
Output: "hello"
Example 2:
Input: "here"
Output: "here"
Example 3:
Input: "LOVELY"
Output: "lovely"
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i < str.size();i++) {
			str[i] = tolower(str[i]);
		}
		return str;
	}
};

//int main() {
//	string str = "FUckU";
//	Solution sol;
//	cout << sol.toLowerCase(str) << endl;
//}