//leetcode83:Remove Duplicates from Sorted List
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *first = head, *second = head->next;
		while (second != nullptr) {
			if (first->val == second->val) {
				ListNode *tmp = second;
				first->next = second->next;
				second = second->next;
				delete tmp;
			}
			else {
				first = first->next;
				second = second->next;
			}
		}
		return head;
	}
};