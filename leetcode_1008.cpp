//leetcode1008:Construct Binary Search Tree from Preorder Traversal
/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)



Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Note:

1 <= preorder.length <= 100
The values of preorder are distinct.

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
//	TreeNode* bstFromPreorder(vector<int>& preorder) {
//		if (preorder.empty()) return nullptr;
//		TreeNode *root = new TreeNode(preorder[0]);
//		for (int i = 1; i < preorder.size(); ++i) {
//			bstInsert(root, preorder[i]);
//		}
//		return root;
//	}
//	void bstInsert(TreeNode *root, int val) {
//		if (val < root->val) {
//			if (root->left == nullptr) root->left = new TreeNode(val);
//			else bstInsert(root->left, val);
//		}
//		else {
//			if (root->right == nullptr) root->right = new TreeNode(val);
//			else bstInsert(root->right, val);
//		}
//	}
//};

class Solution {
public:
	int i = 0;
	TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {
		if (i >= preorder.size() || preorder[i] > bound) return nullptr;
		TreeNode *root = new TreeNode(preorder[i++]);
		root->left = bstFromPreorder(preorder, root->val);
		root->right = bstFromPreorder(preorder, bound);
		return root;
	}
};