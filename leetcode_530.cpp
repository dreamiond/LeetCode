//leetcode530:Minimum Absolute Difference in BST
/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

1
\
3
/
2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note: There are at least two nodes in this BST.
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

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		int res = 0x7FFFFFFF;
		int last = root->val - 0x7FFFFFFF;
		recurse(root, last, res);
		return res;
	}
	void recurse(TreeNode *root, int &last,int &minimum) {
		if (root == nullptr) return;
		recurse(root->left, last, minimum);
		minimum = min(root->val-last, minimum);
		last = root->val;
		recurse(root->right, last, minimum);
	}
};