//leetcode771:Jewels and Stones
/*
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have.  
Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".
Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:
Input: J = "z", S = "ZZ"
Output: 0
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_multiset<char> umc;
		int res = 0;
		for(auto stone:S) {
			umc.insert(stone);
		}
		for (auto jewel : J) {
			int num = umc.count(jewel);
			res += num;
		}
		return res;
	}
};

//int main() {
//	string J = "aA";
//	string S = "aAbbbb";
//	Solution sol;
//	cout << sol.numJewelsInStones(J, S) << endl;
//}