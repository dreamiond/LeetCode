//leetcode94:Binary Tree Inorder Traversal
/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
2
/
3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//用栈实现非递归版本的中序遍历
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> res;
		while (root || !stk.empty()) {
			while (root) {
				stk.push(root);
				root = root->left;
			}
			TreeNode *tmp = stk.top();
			stk.pop();
			res.push_back(tmp->val);
			root = tmp->right;
		}
		return res;
	}
};