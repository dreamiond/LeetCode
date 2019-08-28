//leetcode938:Range Sum of BST
/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.



Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23


Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
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

//class Solution {
//public:
//	int rangeSumBST(TreeNode* root, int L, int R) {
//		int res = 0;
//		LDR(root, L, R, res);
//		return res;
//	}
//	void LDR(TreeNode *root, int L, int R, int &sum) {
//		if (root == nullptr) return;
//		LDR(root->left, L, R, sum);
//		if (root->val > R) return;
//		if (root->val >= L) sum += root->val;
//		LDR(root->right, L, R, sum);
//	}
//};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (root == nullptr) return 0;
		if (root->val > R) return rangeSumBST(root->left, L, R);
		else if (root->val < L) return rangeSumBST(root->right, L, R);
		else return root->val + rangeSumBST(root->left, L, root->val) + rangeSumBST(root->right, root->val, R);
	}
};