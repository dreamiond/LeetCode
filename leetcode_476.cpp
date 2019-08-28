//leetcode476:Number Complement
/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer¡¯s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
	int findComplement(int num) {
		vector<int> binaryNum = {};
		int res=0;
		while (num != 0) {
			binaryNum.push_back(num % 2);
			num /= 2;
		}
		for (int i = 0; i < binaryNum.size(); i++) {
			if (binaryNum[i] == 0) {
				//cout << "binaryNum.size()-1-i:" << binaryNum.size() - 1 - i;
				res += pow(2, i);
			}
		}
		//for (auto i : binaryNum) cout << i << ' ';
		return res;
	}
};

//void main() {
//	Solution sol;
//	sol.findComplement(5);
//}