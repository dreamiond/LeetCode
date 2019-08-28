//leetcode687:Longest Univalue Path
/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

5
/ \
4   5
/ \   \
1   1   5
Output:

2
Example 2:

Input:

1
/ \
4   5
/ \   \
4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
	int longestUnivaluePath(TreeNode* root) {
		int res = 0;
		dfs(root, res);
		return res;
	}
	int depth(TreeNode* root,int value) {
		if (root == nullptr) return 0;
		if (root->val != value) return 0;
		return max(depth(root->left, value), depth(root->right, value)) + 1;
	}
	void dfs(TreeNode* root, int &maximum) {
		if (root == nullptr) return;
		int length = depth(root->left, root->val) + depth(root->right, root->val);
		maximum = max(maximum, length);
		dfs(root->left, maximum);
		dfs(root->right, maximum);
	}
};