//leetcode100:Same Tree
/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
/ \       / \
2   3     2   3

[1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
/           \
2             2

[1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
/ \       / \
2   1     1   2

[1,2,1],   [1,1,2]

Output: false
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	bool isSameTree(TreeNode* p, TreeNode* q) {
//		vector<int> preP, preQ, midP, midQ;
//		preOrder(p, preP); preOrder(q, preQ);
//		if (preP != preQ) return false;
//		midOrder(p, midP); midOrder(q, midQ);
//		if (midP != midQ) return false;
//		return true;
//	}
//	void preOrder(TreeNode *root, vector<int> &v) {
//		if (root == nullptr) return;
//		v.push_back(root->val);
//		preOrder(root->left,v);
//		preOrder(root->right,v);
//	}
//	void midOrder(TreeNode *root, vector<int> &v) {
//		if (root == nullptr) return;
//		midOrder(root->left, v);
//		v.push_back(root->val);
//		midOrder(root->right, v);
//	}
//};​

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr || q == nullptr) return p == q;
		return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	}
};