//leetcode572:Subtree of Another Tree
/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

3
/ \
4   5
/ \
1   2
Given tree t:
4
/ \
1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

3
/ \
4   5
/ \
1   2
/
0
Given tree t:
4
/ \
1   2
Return false.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

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
//	bool isSubtree(TreeNode* s, TreeNode* t) {
//		bool res = false;
//		DFS(s, t, res);
//		return res;
//	}
//	void DFS(TreeNode *s, TreeNode* t, bool &res) {
//		if (s == nullptr) return;
//		if (isSameTree(s, t)) {
//			res = true;
//			return;
//		}
//		DFS(s->left, t, res);
//		DFS(s->right, t, res);
//	}
//	bool isSameTree(TreeNode* a, TreeNode* b) {
//		if (a == nullptr && b == nullptr) return true;
//		else if (a == nullptr || b == nullptr) return false;
//		return (a->val == b->val) && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
//	}
//};

/*
Two trees are identical when they are recursively identical. 
Brute force solution would be recursively compare each node in s with t to check for identical. 
Better solution is to only compare nodes in s with the same max depth as t. 
First get max depth of t, then recursively check each node in s, if depth equals, push to a vector. 
Then compare each node in the vector with t.
*/

class Solution {
	vector<TreeNode*> nodes;

public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		if (!s || !t) return false;

		getDepth(s, getDepth(t, -1));

		for (TreeNode* n : nodes)
			if (identical(n, t))
				return true;

		return false;
	}

	int getDepth(TreeNode* r, int d) {
		if (!r)
			return -1;

		int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

		// Check if depth equals required value
		// Require depth is -1 for tree t (only return the depth, no push)
		if (depth == d)
			nodes.push_back(r);

		return depth;
	}

	bool identical(TreeNode* a, TreeNode* b) {
		if (!a && !b) return true;
		if (!a || !b || a->val != b->val) return false;

		return identical(a->left, b->left) && identical(a->right, b->right);
	}
};