//leetcode894:All Possible Full Binary Trees
/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.



Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:



Note:

1 <= N <= 20
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

//TreeNode *copy(TreeNode *root) {
//	TreeNode *newRoot = new TreeNode(0);
//	newRoot->left = root->left == nullptr ? nullptr : copy(root->left);
//	newRoot->right = root->right == nullptr ? nullptr : copy(root->right);
//	return newRoot;
//}
//
//class Solution {
//public:
//	vector<TreeNode*> allPossibleFBT(int N) {
//		vector<TreeNode*> res;
//		if (N == 1) res.emplace_back(new TreeNode(0));
//		else if (N % 2 != 0) {//不能是偶数
//			for (int i = 2; i < N; i += 2) {//i代表middle
//				auto left = allPossibleFBT(i - 1);
//				auto right = allPossibleFBT(N - i);
//				for (int l = 0; l < left.size(); ++l) {
//					for (int r = 0; r < right.size(); ++r) {
//						res.push_back(new TreeNode(0));
//						res.back()->left = (r == right.size() - 1) ? left[l] : copy(left[l]);
//						res.back()->right = (l == left.size() - 1) ? right[r] : copy(right[r]);
//					}
//				}
//			}
//		}
//		return res;
//	}
//};

//TreeNode* clone(TreeNode* root) {
//	TreeNode* new_root = new TreeNode(0);
//	new_root->left = (root->left) ? clone(root->left) : nullptr;
//	new_root->right = (root->right) ? clone(root->right) : nullptr;
//	return new_root;
//}
//
//vector<TreeNode*> allPossibleFBT(int N) {
//	vector<TreeNode*> ret;
//
//	if (0 == N % 2) {
//		return ret;
//	}
//
//	if (1 == N) {
//		return vector<TreeNode*>{new TreeNode(0)};
//	}
//
//	// For each level, holds all the patterns for all the full BST
//	vector<vector<unique_ptr<TreeNode>>> patterns;
//	patterns.emplace_back();
//	patterns.back().emplace_back(new TreeNode(0));
//
//	// Build up a pattern for all the balanaced trees using n - 2 nodes. Branches that form the patterns are 
//	// deliberately linked together for efficency. It is not safe to return this, a full clone of
//	// each pattern will be required
//	for (int lvl = 1; lvl <= N / 2 - 1; ++lvl) {
//		patterns.emplace_back();
//		for (int r = 0; r < lvl; ++r) {
//			for (auto& left : patterns[r]) {
//				for (auto& right : patterns[lvl - r - 1]) {
//					patterns.back().emplace_back(new TreeNode(0));
//					patterns.back().back()->left = left.get();
//					patterns.back().back()->right = right.get();
//				}
//			}
//		}
//	}
//
//	// Final level should actually create a tree that can be returned from the patterns generate above
//	for (int r = 0; r < N / 2; ++r) {
//		for (auto& left : patterns[r]) {
//			for (auto& right : patterns[N / 2 - r - 1]) {
//				ret.emplace_back(new TreeNode(0));
//				ret.back()->left = clone(left.get());
//				ret.back()->right = clone(right.get());
//			}
//		}
//	}
//
//	return ret;
//}


class Solution {
private:
	unordered_map<int, vector<TreeNode*>> cache;
public:
	vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> res;
		if (cache[N].size() != 0) return cache[N];
		if (N == 1) res.push_back(new TreeNode(0));
		else if (N % 2 != 0) {
			for (int i = 1; i < N; i += 2) {
				int left = i, right = N - i - 1;
				for (auto l : allPossibleFBT(left)) {
					for (auto r : allPossibleFBT(right)) {
						res.push_back(new TreeNode(0));
						res.back()->left = l;
						res.back()->right = r;
					}
				}
			}
		}
		cache[N] = res;
		return res;
	}
};