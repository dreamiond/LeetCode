//leetcode513:Find Bottom Left Tree Value
/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

2
/ \
1   3

Output:
1
Example 2:
Input:

1
/ \
2   3
/   / \
4   5   6
/
7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
	int findBottomLeftValue(TreeNode* root) {
		int res = root->val;
		int resLev = 0;
		helper(root, 0, res, resLev);
		return res;
	}

	void helper(TreeNode* root, int level, int &res,int &resLev) {
		if (root == nullptr) return;
		helper(root->left, level + 1, res, resLev);
		helper(root->right, level + 1, res, resLev);
		if (level > resLev) {
			res = root->val;
			resLev = level;
		}
	}
};