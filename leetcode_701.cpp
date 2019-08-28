//leetcode701:Insert into a Binary Search Tree
/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example,

Given the tree:
4
/ \
2   7
/ \
1   3
And the value to insert: 5
You can return this binary search tree:

4
/   \
2     7
/ \   /
1   3 5
This tree is also valid:

5
/   \
2     7
/ \
1   3
\
4
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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		TreeNode *pos = insertPos(root, val);
		if (val < pos->val) pos->left = new TreeNode(val);
		else pos->right = new TreeNode(val);
		return root;
	}
	TreeNode* insertPos(TreeNode* root, int val) {
		if (root->left == nullptr && root->right == nullptr) return root;
		if (root->left != nullptr && root->right == nullptr) {
			//�����ӣ�û���Һ���
			if (val < root->val) return insertPos(root->left, val);
			else return root;
		}
		if (root->left == nullptr && root->right != nullptr) {
			//���Һ��ӣ�û������
			if (val > root->val) return insertPos(root->right, val);
			else return root;
		}
		else {
			if (val < root->val) return insertPos(root->left, val);
			else return insertPos(root->right, val);
		}
	}
};