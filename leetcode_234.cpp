//leetcode234:Palindrome Linked List
/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return true;
		ListNode *slow = head, *fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *back = reverse(slow->next);
		while (back != nullptr) {
			cout << "head:" << head->val << " back:" << back->val << endl;
			if (head->val != back->val) return false;
			head = head->next;
			back = back->next;
		}
		return true;
	}
	ListNode* reverse(ListNode* p) {
		ListNode *pre = nullptr, *back = nullptr;
		while (p != nullptr) {
			back = p->next;
			p->next = pre;
			pre = p;
			p = back;
		}
		return pre;
	}
};