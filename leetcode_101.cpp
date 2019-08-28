//leetcode101:Symmetric Tree
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
1
/ \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include<queue>

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
//	bool isSymmetric(TreeNode* root) {
//		vector<vector<int>> v;
//		DFS(root, 0, v);
//		for (auto line : v) {
//			if (!isSymVector(line)) return false;
//		}
//		return true;
//	}
//	void DFS(TreeNode *root, int floor, vector<vector<int>> &v) {
//		if (v.size() == floor) v.push_back(vector<int>(0, 0));
//		if (root == nullptr) {
//			v[floor].push_back(NULL);
//			return;
//		}
//		v[floor].push_back(root->val);
//		DFS(root->left, floor + 1, v);
//		DFS(root->right, floor + 1, v);
//	}
//	bool isSymVector(vector<int> v) {
//		for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
//			if (v[i] != v[j]) return false;
//		}
//		return true;
//	}
//};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		TreeNode *left, *right;
		if (!root)
			return true;

		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()) {
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (NULL == left && NULL == right)
				continue;
			if (NULL == left || NULL == right)
				return false;
			if (left->val != right->val)
				return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}
};