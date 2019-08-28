//leetcode326:Power of Three
/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		if (n < 1) return false;
//		double error = 1e-10;
//		double x = log(n) / log(3);
//		int x2 = floor(x + 0.5);
//		if (abs(x - x2) < error) return true;
//		return false;
//	}
//};


class Solution {
public:
	const int MAX3PowerInt = 1162261467; //3^19
	bool isPowerOfThree(int n) {
		if (n < 1) return false;
		if (MAX3PowerInt%n == 0) return true;
		return false;
	}
};