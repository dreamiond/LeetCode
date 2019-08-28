//leetcode434:Number of Segments in a String
/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
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
	int countSegments(string s) {
		stringstream ss(s);
		int res = 0;
		string tmp = "";
		while (ss >> tmp) ++res;
		return res;
	}
};