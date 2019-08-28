//leetcode852:Peak Index in a Mountain Array
/*
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int l = 0, h = A.size() - 1, mid;
		while (mid!=0&&l < h) {
			mid = (l + h) / 2;
			if (A[mid] < A[mid + 1]) l = mid+1;
			else if (A[mid] < A[mid - 1]) h = mid-1;
			else return mid;
		}
		return (A[l] > A[h] ? l : h);
	}
};

//int main() {
//	vector<int> v = { 1,2,3,4,5,4,2,1 };
//	Solution sol;
//	cout<<sol.peakIndexInMountainArray(v);
//}