//leetcode102:Binary Tree Level Order Traversal
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归做法

//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> res;
//		if (!root) return res;
//		helper(root, 0, res);
//		return res;
//	}
//
//	void helper(TreeNode *root, int level, vector<vector<int>> &res) {
//		if (root == nullptr) return;
//		if (level == res.size()) res.emplace_back(vector<int>());
//		res[level].emplace_back(root->val);
//		helper(root->left, level + 1, res);
//		helper(root->right, level + 1, res);
//	}
//};

//非递归做法

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<pair<TreeNode*, int>> q;//int代表所在层数
		vector<vector<int>> res;
		if (!root) return res;
		q.push({ root,0 });
		while (!q.empty()) {
			if (res.size() == q.front().second) res.emplace_back(vector<int>());
			res[q.front().second].emplace_back(q.front().first->val);
			if (q.front().first->left)q.push({ q.front().first->left, q.front().second + 1 });
			if (q.front().first->right)q.push({ q.front().first->right, q.front().second + 1 });
			q.pop();
		}
		return res;
	}
};