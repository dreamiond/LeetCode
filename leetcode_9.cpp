//leetcode9:Palindrome Number
/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
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
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int n = 0;
		while (pow(10, n) <= x)++n;
		--n;
		cout << n << endl;
		for (int i = 0; i < (n + 1) / 2; ++i) {
			int a = int(x / pow(10, i)) % 10, b = int(x / pow(10, n - i)) % 10;
			//cout << a << " " << b;
			if (a != b) return false;
		}
		return true;
	}
};

//void main() {
//	Solution sol;
//	sol.isPalindrome(10);
//}