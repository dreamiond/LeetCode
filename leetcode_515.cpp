//leetcode515:Find Largest Value in Each Tree Row
/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

1
/ \
3   2
/ \   \
5   3   9

Output: [1, 3, 9]
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
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		helper(root, 0, res);
		return res;
	}

	void helper(TreeNode *root, int level, vector<int> &res) {
		if (root == nullptr) return;
		if (level == res.size()) res.push_back(root->val);
		else res[level] = max(res[level], root->val);
		helper(root->left, level + 1, res);
		helper(root->right, level + 1, res);
	}
};