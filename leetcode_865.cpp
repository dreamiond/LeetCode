//leetcode865:Smallest Subtree with all the Deepest Nodes
/*

Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.



Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:



We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.


Note:

The number of nodes in the tree will be between 1 and 500.
The values of each node are unique.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//构造并查集，慢，要遍历3遍

//class Solution {
//private:
//	map<int, int> father;
//	vector<int> deepestNodes;
//	int deepestDepth = 0;
//public:
//	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//		if (root->left == nullptr && root->right == nullptr) return root;
//		findDeepestNodes(root, 1);
//		if (deepestNodes.size() == 1) return findNode(root, deepestNodes[0]);
//
//		while (!haveTheSameFather()) {
//			for (auto node : deepestNodes) {
//				father[node] = father[father[node]];
//			}
//		}
//
//		int resNum = father[deepestNodes[0]];
//		return findNode(root, resNum);
//	}
//
//	void findDeepestNodes(TreeNode *root, int depth) {
//		if (root == nullptr) return;
//		findDeepestNodes(root->left, depth + 1);
//		findDeepestNodes(root->right, depth + 1);
//		if (depth > deepestDepth) {
//			deepestNodes.clear();
//			deepestNodes.push_back(root->val);
//			deepestDepth = depth;
//		}
//		else if (depth == deepestDepth) {
//			deepestNodes.push_back(root->val);
//		}
//
//		//构造并查集
//		if (root->left) {
//			father[root->left->val] = root->val;
//		}
//		if (root->right) {
//			father[root->right->val] = root->val;
//		}
//	}
//
//	TreeNode* findNode(TreeNode *root, int num) {
//		if (root == nullptr) return nullptr;
//		if (root->val == num) return root;
//		TreeNode *left = findNode(root->left, num);
//		TreeNode *right = findNode(root->right, num);
//		if (left != nullptr) return left;
//		else if (right != nullptr) return right;
//		else return nullptr;
//	}
//
//	bool haveTheSameFather() {
//		int num = father[deepestNodes[0]];
//		for (auto node : deepestNodes) {
//			if (father[node] != num) return false;
//		}
//		return true;
//	}
//};


//one-pass算法，构造pair<TreeNode*,int>
//TreeNode*代表：当前节点的子树内，最深节点们的最深公共子节点
//int代表：当前节点的子树内，最深节点的深度

class Solution {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		pair<TreeNode*, int> res = helper(root);
		return res.first;
	}

	pair<TreeNode*, int> helper(TreeNode *root) {
		if (root == nullptr) {
			return { nullptr,0 };
		}
		pair<TreeNode*, int> left = helper(root->left);
		pair<TreeNode*, int> right = helper(root->right);
		if (left.second < right.second) {
			return { right.first,right.second + 1 };
		}
		else if (left.second > right.second) {
			return { left.first,left.second + 1 };
		}
		else {
			return { root,right.second + 1 };
		}
	}
};