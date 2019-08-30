//leetcode1147:Longest Chunked Palindrome Decomposition
/*
Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:

Each a_i is a non-empty string;
Their concatenation a_1 + a_2 + ... + a_k is equal to text;
For all 1 <= i <= k,  a_i = a_{k+1 - i}.


Example 1:

Input: text = "ghiabcdefhelloadamhelloabcdefghi"
Output: 7
Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
Example 2:

Input: text = "merchant"
Output: 1
Explanation: We can split the string on "(merchant)".
Example 3:

Input: text = "antaprezatepzapreanta"
Output: 11
Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
Example 4:

Input: text = "aaa"
Output: 3
Explanation: We can split the string on "(a)(a)(a)".


Constraints:

text consists only of lowercase English characters.
1 <= text.length <= 1000
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestDecomposition(string text) {

	}
};

//class Solution {
//public:
//	int longestDecomposition(string S) {
//		int res = 0, n = S.size();
//		string l = "", r = "";
//		for (int i = 0; i < n; ++i) {
//			l = l + S[i], r = S[n - i - 1] + r;
//			if (l == r) {
//				++res;
//				l = "", r = "";
//			}
//		}
//		return res;
//	}
//};

class Solution {
public:
	int longestDecomposition(string S, int res = 0) {
		int n = S.length();
		for (int i = 1; i <= n / 2; ++i) {
			if (S[0] == S[n - i] && S[i - 1] == S[n - 1]) {
				if (S.substr(0, i) == S.substr(n - i)) {
					return longestDecomposition(S.substr(i, n - i - i), res + 2);
				}
			}
		}
		return n ? res + 1 : res;
	}
};