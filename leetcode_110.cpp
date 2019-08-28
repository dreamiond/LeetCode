//leetcode110:Balanced Binary Tree
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

3
/ \
9  20
/  \
15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

1
/ \
2   2
/ \
3   3
/ \
4   4
Return false.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

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
//	bool isBalanced(TreeNode* root) {
//		bool res = true;
//		DFS(root, res);
//		return res;
//	}
//	int height(TreeNode* root) {
//		if (root == nullptr) return 0;
//		return max(height(root->left), height(root->right)) + 1;
//	}
//	void DFS(TreeNode *root, bool &res) {
//		if (root == nullptr) return;
//		if (abs(height(root->left) - height(root->right)) > 1) {
//			res = false;
//			return;
//		}
//		DFS(root->left, res);
//		DFS(root->right, res);
//	}
//};

class Solution {
public:
	int DFS(TreeNode *root) {
		if (root == nullptr) return 0;

		int leftHeight = DFS(root->left);
		if (leftHeight == -1) return -1;
		int rightHeight = DFS(root->right);
		if (rightHeight == -1) return -1;

		if (abs(leftHeight - rightHeight) > 1) return -1;
		return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode* root) {
		return DFS(root) != -1;
	}
};