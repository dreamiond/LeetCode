//leetcode1026:Maximum Difference Between Node and Ancestor
/*
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)



Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation:
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


Note:

The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

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
	int maxAncestorDiff(TreeNode* root) {
		int res = 0;
		minInSubTree(root, res);
		maxInSubTree(root, res);
		return res;
	}
	int minInSubTree(TreeNode *root, int &res) {
		if (root == nullptr) return 200000;
		int left = 200000, right = 200000;
		if (root->left) left = min(minInSubTree(root->left, res), root->left->val);
		if (root->right) right = min(minInSubTree(root->right, res), root->right->val);
		int minimum = min(left, right);
		res = max(res, root->val - minimum);
		return minimum;
	}
	int maxInSubTree(TreeNode *root, int &res) {
		if (root == nullptr) return -1;
		int left = -1, right = -1;
		if (root->left) left = max(maxInSubTree(root->left, res), root->left->val);
		if (root->right) right = max(maxInSubTree(root->right, res), root->right->val);
		int maximum = max(left, right);
		res = max(res, maximum-root->val);
		return maximum;
	}
};