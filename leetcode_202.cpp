//leetcode202:Happy Number
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	bool isHappy(int n) {
//		vector<int> num;
//		vector<vector<int>> dict;
//		while (n) {
//			num.push_back(n % 10);
//			n /= 10;
//		}
//		while (1) {
//			if (find(dict,num)) return false;
//			if (happyVec(num)) return true;
//			dict.emplace_back(num);
//			num = reGenerate(num);
//		}
//		return true;
//	}
//	bool happyVec(vector<int> v) {
//		int one = 1;
//		for (auto i : v) {
//			if (i == 0) continue;
//			else if (i == 1) {
//				if (one == 0) return false;
//				--one;
//			}
//			else return false;
//		}
//		return true;
//	}
//	vector<int> reGenerate(vector<int> v) {
//		vector<int> res;
//		int num = 0;
//		for (auto i : v) num =num + pow(i, 2);
//		while (num) {
//			res.push_back(num % 10);
//			num /= 10;
//		}
//		return res;
//	}
//	bool find(vector<vector<int>> a, vector<int> b) {
//		for (auto i : a) {
//			if (i == b) return true;
//		}
//		return false;
//	}
//};

//class Solution {
//public:
//	int digitSquareSum(int n) {
//		int sum = 0, tmp;
//		while (n) {
//			tmp = n % 10;
//			sum += tmp * tmp;
//			n /= 10;
//		}
//		return sum;
//	}
//
//	bool isHappy(int n) {
//		int slow, fast;
//		slow = fast = n;
//		do {
//			slow = digitSquareSum(slow);
//			fast = digitSquareSum(fast);
//			fast = digitSquareSum(fast);
//		} while (slow != fast);
//		if (slow == 1) return 1;
//		else return 0;
//	}
//};
//
//void main() {
//	int n = 19;
//	Solution sol;
//	cout << sol.isHappy(18) << endl;
//}