//leetcode653:Two Sum IV - Input is a BST
/*

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
5
/ \
3   6
/ \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
5
/ \
3   6
/ \   \
2   4   7

Target = 28

Output: False
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

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
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> usi;
		bool res = false;
		recursiveTravel(root, usi, k, res);
		return res;
	}
	void recursiveTravel(TreeNode* root, unordered_set<int> &usi, int k, bool &match) {
		if (root == nullptr) return;
		if (usi.find(k - root->val) != usi.end()) match = true;
		usi.insert(root->val);
		recursiveTravel(root->left, usi, k, match);
		recursiveTravel(root->right, usi, k, match);
	}
};