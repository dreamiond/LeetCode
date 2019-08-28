//leetcode703:Kth Largest Element in a Stream
/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ¡Ý k-1 and k ¡Ý 1.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include<iterator>
#include<xfunctional>
#include<queue>

using namespace std;

//class KthLargest {
//private:
//	multiset<int,greater<int> > nums;
//	int k;
//	int getValue() {
//		auto it = nums.begin();
//		for (int i = 0; i < k-1; ++i) ++it;
//		return *it;
//	}
//public:
//	KthLargest(int k, vector<int> nums) {
//		for (auto i : nums) this->nums.insert(i);
//		this->k = k;
//	}
//
//	int add(int val) {
//		nums.insert(val);
//		return getValue();
//	}
//};



//class KthLargest {
//private:
//	priority_queue<int, vector<int>,greater<int> > q;
//	int size;
//public:
//	KthLargest(int k, vector<int> nums) {
//		size = k;
//		for (auto i : nums) {
//			q.push(i);
//			if (q.size() > size) q.pop();
//		}
//	}
//
//	int add(int val) {
//		q.push(val);
//		if (q.size() > size) q.pop();
//		return q.top();
//	}
//};




/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest obj = new KthLargest(k, nums);
* int param_1 = obj.add(val);
*/