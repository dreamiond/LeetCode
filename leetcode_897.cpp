//leetcode897:Increasing Order Search Tree
/*
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

5
/ \
3    6
/ \    \
2   4    8
/        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

1
\
2
\
3
\
4
\
5
\
6
\
7
\
8
\
9
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
*/

#include <iostream>
#include <vector>
#include <string>

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
	TreeNode* basic = new TreeNode(31415926);
	TreeNode* increasingBST(TreeNode* root) {
		midIterator(root);
		return basic->right;
	}
	void midIterator(TreeNode* root) {
		if (root != NULL) {
			midIterator(root->left);
			insertNode(basic, root->val);
			midIterator(root->right);
			cout << "É¾³ý" << root->val << endl;
			//delete root;
		}
	}
	void insertNode(TreeNode* root, int val) {
		while (root->right != nullptr) root = root->right;
		cout << "ÔÚ" << root->val << "µÄÓÒ±ß²åÈë" << val << endl;
		root->right = new TreeNode(val);
		root->right->left = nullptr;
		root->right->right = nullptr;
		root->left = nullptr;
	}
};

//void main() {
//	TreeNode* root = new TreeNode(5);
//	root->left = new TreeNode(3);
//	root->right = new TreeNode(6);
//	root->left->left = new TreeNode(2);
//	root->left->right = new TreeNode(4);
//	root->right->right = new TreeNode(8);
//	root->left->left->left = new TreeNode(1);
//	root->right->right->left = new TreeNode(7);
//	root->right->right->right = new TreeNode(9);
//	Solution sol;
//	sol.increasingBST(root);
//}