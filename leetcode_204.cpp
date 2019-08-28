//leetcode204:Count Primes
/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	////ÊÔ³ý·¨
	//int countPrimes(int n) {
	//	if (n <= 2) return 0;
	//	if (n == 3) return 1;
	//	vector<int> primeNumber = { 2 };
	//	for (int i = 3; i < n; ++i) {
	//		if (i % 2 == 0) continue;
	//		int limition = sqrtf(i);
	//		int j = 0;
	//		for (; j < primeNumber.size() && primeNumber[j] <= limition; ++j) {
	//			if (i%primeNumber[j] == 0) break;
	//		}
	//		if (j == primeNumber.size()) primeNumber.push_back(i);
	//		else if (primeNumber[j] > limition) primeNumber.push_back(i);
	//	}
	//	for (auto i : primeNumber) cout << i << endl;
	//	return primeNumber.size();
	//}

	//É¸·¨
	int countPrimes(int n) {
		if (n <= 2) return 0;
		vector<bool> dict(n, true);
		dict[0] = false; dict[1] = false;
		for (int i = 2; i < n; ++i) {
			if (dict[i] == false) continue;
			for (int j = 2; j*i < n; ++j) {
				dict[j*i] = false;
			}
		}
		int res = 0;
		for (auto i : dict) {
			if (i == true) res++;
		}
		return res;
	}
};

//void main() {
//	Solution sol;
//	sol.countPrimes(10);
//}