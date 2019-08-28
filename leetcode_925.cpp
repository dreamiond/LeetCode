//leetcode925:Long Pressed Name
/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.


Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int n = 0, t = 0;
		if (name[0] != typed[0]) return false;
		while (n < name.size() && t < typed.size()) {
			if (name[n] == typed[t]) {
				//printf("%c=%c\n", name[n], typed[t]);
				++n; ++t;
			}
			else if (name[n - 1] == typed[t]) {
				//printf("%c=%c\n", name[n - 1], typed[t]);
				++t;
			}
			else return false;
		}
		if (n != name.size()) return false;
		return true;
	}
};

//void main() {
//	string a = "alex", b = "aaleex";
//	Solution sol;
//	sol.isLongPressedName(a, b);
//}