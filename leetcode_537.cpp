//leetcode537:Complex Number Multiplication
/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <sstream>

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
		char buff = ' ';
		stringstream aa(a), bb(b);
		aa >> a1 >> buff >> a2 >> buff;
		bb >> b1 >> buff >> b2 >> buff;
		int res1 = a1*b1 - a2*b2;
		int res2 = a1*b2 + a2*b1;
		return to_string(res1) + "+" + to_string(res2) + "i";
	}
};

//void main() {
//	string s = "1+2";
//	int pos = s.find('+');
//	cout << s.substr(0, pos);
//	cout << s.substr(pos + 1, s.size() - pos - 1);
//}