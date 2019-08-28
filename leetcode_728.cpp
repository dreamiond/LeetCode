//leetcode728:Self Dividing Numbers
/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> divide(int num) {
		vector<int> res;
		while (num != 0) {
			res.push_back(num % 10);
			num /= 10;
		}
		return res;
	}

	bool isSelfDividingNumber(int num) {
		vector<int> divided_num = divide(num);
		for (auto i : divided_num) {
			if (i == 0) return false;
			if (num%i != 0) return false;
		}
		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int i = left; i < right+1; i++) {
			if (isSelfDividingNumber(i)) res.push_back(i);
		}
		return res;
	}
};

//void main() {
//	int left = 1, right = 22;
//	Solution sol;
//	vector<int> res = sol.selfDividingNumbers(left, right);
//	for (auto i : res) {
//		cout << i << ' ';
//	}
//}