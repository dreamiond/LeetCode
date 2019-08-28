//leetcode206:Reverse Linked List
/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return head;
		ListNode* left = head, *middle=nullptr, *right=nullptr;
		if(left) middle = left->next;
		if(middle) right = middle->next;
		left->next = nullptr;
		while (middle != nullptr) {
			middle->next = left;
			left = middle;
			middle = right;
			if(right) right = right->next;
		}
		return left;
	}
};