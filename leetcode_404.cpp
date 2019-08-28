//leetcode404:Sum of Left Leaves
/*
Find the sum of all left leaves in a given binary tree.

Example:

3
/ \
9  20
/  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
	int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
		recurse(root, res);
		return res;
	}
	void recurse(TreeNode* root, int &res) {
		if (root == nullptr) return;
		if (root->left != nullptr&&root->left->left == nullptr&&root->left->right == nullptr) res += root->left->val;
		recurse(root->left, res);
		recurse(root->right, res);
	}
};