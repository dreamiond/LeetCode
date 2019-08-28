//leetcode951:Flip Equivalent Binary Trees
/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.



Example 1:

Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Flipped Trees Diagram


Note:

Each tree will have at most 100 nodes.
Each value in each tree will be a unique integer in the range [0, 99].
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
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2) return true;
		if (!equal(root1,root2)) return false;
		if (equal(root1->left, root2->left) && equal(root1->right, root2->right)) {
			return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
		}
		else if (equal(root1->left, root2->right) && equal(root1->right, root2->left)) {
			return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
		}
		else return false;
	}
	bool equal(TreeNode *a, TreeNode *b) {
		if (a == nullptr && b == nullptr) return true;
		if (a == nullptr && b != nullptr) return false;
		if (a != nullptr && b == nullptr) return false;
		if (a->val == b->val) return true;
		return false;
	}
};