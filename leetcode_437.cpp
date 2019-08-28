//leetcode437:Path Sum III
/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

10
/  \
5   -3
/ \    \
3   2   11
/ \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

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
	int pathSum(TreeNode* root, int sum) {
		int res = 0;
		DFS(root, sum, res);
		return res;
	}

	void DFS(TreeNode* root, int sum, int &res) {
		if (root == nullptr) return;
		res += numOfPathFromRoot(root, sum, 0);
		DFS(root->left, sum, res);
		DFS(root->right, sum, res);
	}

	int numOfPathFromRoot(TreeNode *root, int sum,int n) {
		if (root == nullptr) return 0;
		if (n + root->val == sum) return numOfPathFromRoot(root->left, sum, n + root->val) + numOfPathFromRoot(root->right, sum, n + root->val) + 1;
		else return numOfPathFromRoot(root->left, sum, n + root->val) + numOfPathFromRoot(root->right, sum, n + root->val);
	}
};

