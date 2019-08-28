//leetcode257:Binary Tree Paths
/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

1
/   \
2     3
\
5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string s = "";
		recurse(root, s, res);
		return res;
	}
	void recurse(TreeNode* root, string s, vector<string> &res) {
		if (root == nullptr) return;
		if (root->left == nullptr && root->right == nullptr) {
			s += to_string(root->val);
			res.push_back(s);
			return;
		}
		recurse(root->left, s + to_string(root->val) + "->", res);
		recurse(root->right, s + to_string(root->val) + "->", res);
	}
};