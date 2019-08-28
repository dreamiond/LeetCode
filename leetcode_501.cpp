//leetcode501:Find Mode in Binary Search Tree
/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


For example:
Given BST [1,null,2,2],

1
\
2
/
2


return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).


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
	vector<int> findMode(TreeNode* root) {
		unordered_map<int, int> dict;
		midTravel(root, dict);
		int max = 0;
		vector<int> res;
		/*for (auto i : dict) {
			if (i.second > max) {
				res.clear();
				res.push_back(i.first);
				max = i.second;
			}
			else if (i.second == max) {
				res.push_back(i.first);
			}
		}*/
		for (auto i : dict) {
			max = i.second > max ? i.second : max;
		}
		for (auto i : dict) {
			if (i.second == max) res.push_back(i.first);
		}
		return res;
	}
	void midTravel(TreeNode* root, unordered_map<int, int> &dict) {
		if (root == nullptr) return;
		midTravel(root->left, dict);
		++dict[root->val];
		midTravel(root->right, dict);
	}
};