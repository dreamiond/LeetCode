//leetcode21:Merge Two Sorted Lists
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Definition for singly-linked list.
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//
//class Solution {
//public:
//	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//		ListNode dummy(INT_MIN);
//		ListNode *tail = &dummy;
//
//		while (l1 && l2) {
//			if (l1->val < l2->val) {
//				tail->next = l1;
//				l1 = l1->next;
//			}
//			else {
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//
//		tail->next = l1 ? l1 : l2;
//		return dummy.next;
//	}
//};