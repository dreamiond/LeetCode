//leetcode905:Sort Array By Parity
/*
Given an array A of non-negative integers, 
return an array consisting of all the even elements of A, 
followed by all the odd elements of A.
You may return any answer array that satisfies this condition.
Example 1:
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool IsEven(int i) {
		if (i % 2 == 0) return true;
		else return false;
	}

	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> even_num, odd_num;
		for (int i : A) {
			if (IsEven(i)) even_num.push_back(i);
			else odd_num.push_back(i);
		}
		for (int i = 0; i < even_num.size();i++) {
			A[i] = even_num[i];
		}
		for (int i = even_num.size(),j = 0; i < A.size(); i++,j++) {
			A[i] = odd_num[j];
		}
		return A;
	}
};

//int main() {
//	vector<int> v = { 4,1,3,2 };
//	Solution sol;
//	sol.sortArrayByParity(v);
//	for (auto i : v) {
//		cout << i << " ";
//	}
//}