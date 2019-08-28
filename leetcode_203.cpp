//leetcode203:Remove Linked List Elements
/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr) return head;
		while (head!=nullptr && head->val == val) head = head->next;
		if (head == nullptr) return head;
		ListNode *pre = head, *p = head->next;
		while (p != nullptr) {
			if (p->val == val) {
				pre->next = p->next;
				p = p->next;
			}
			else {
				pre = pre->next;
				p = p->next;
			}
		}
		return head;
	}
};