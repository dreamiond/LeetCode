//leetcode889:Construct Binary Tree from Preorder and Postorder Traversal
/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.



Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]


Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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

class Solution {
private:
	unordered_map<int, int> preMap, postMap; //value->index
public:
	TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
		for (int i = 0; i < pre.size(); ++i) preMap[pre[i]] = i;
		for (int i = 0; i < post.size(); ++i) postMap[post[i]] = i;

		if (pre.size() < 0) return nullptr;
		TreeNode *root = new TreeNode(pre[0]);
		pre[0] = -1; post[post.size() - 1] = -1;
		helper(root, pre, post);
		return root;
	}

	void helper(TreeNode *root, vector<int> &pre,vector<int> &post) {
		int preIdx = preMap[root->val], postIdx = postMap[root->val];
		if (preIdx + 1 < pre.size() && pre[preIdx + 1] > 0) {
			root->left = new TreeNode(pre[preIdx + 1]);
			post[postMap[pre[preIdx + 1]]] = -1;
			pre[preIdx + 1] = -1;
		}
		if (postIdx - 1 >= 0 && post[postIdx - 1] > 0) {
			root->right = new TreeNode(post[postIdx - 1]);
			pre[preMap[post[postIdx - 1]]] = -1;
			post[postIdx - 1] = -1;
		}
		if (root->left != nullptr) helper(root->left, pre, post);
		if (root->right != nullptr) helper(root->right, pre, post);
	}
};