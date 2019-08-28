//leetcode669:Trim a Binary Search Tree
/*
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
1
/ \
0   2

L = 1
R = 2

Output:
1
\
2
Example 2:
Input:
3
/ \
0   4
\
2
/
1

L = 1
R = 3

Output:
3
/
2
/
1
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

//class Solution {
//public:
//	TreeNode* trimBST(TreeNode* root, int L, int R) {
//		deleteNode(root, L, R);
//		if (root->val<L || root->val>R) {
//			//删除root
//			if (root->left == nullptr) {
//				//左子树为空
//				cout << "删除"<<root->val<<"，返回root的右孩子" << endl;
//				TreeNode* temp = root->right;
//				delete root;
//				return temp;
//			}
//			else if (root->right == nullptr) {
//				//右子树为空
//				cout << "删除" << root->val << "，返回root的左孩子" << endl;
//				TreeNode* temp = root->left;
//				delete root;
//				return temp;
//			}
//			else {
//				//左右子树都不空
//				TreeNode* directSuccessor = root->right, *parent = root;
//				while (directSuccessor->left != nullptr) {
//					parent = directSuccessor;
//					directSuccessor = directSuccessor->left;
//				}
//				root->val = directSuccessor->val;
//				cout << "删除" << root->val << "，用"<<directSuccessor->val<<"代替" << endl;
//				deleteLeftNode(parent);
//				return root;
//			}
//		}
//		else {
//			return root;
//		}
//	}
//	void deleteNode(TreeNode* root, int L, int R) {
//		if (root->left == nullptr&&root->right == nullptr) return;
//		while (root->left != nullptr && (root->left->val<L || root->left->val>R)) {
//			cout << "删除" << root->val << "的左孩子" << endl;
//			deleteLeftNode(root);
//		}
//		while (root->right != nullptr && (root->right->val<L || root->right->val>R)) {
//			deleteRightNode(root);
//			cout << "删除" << root->val << "的右孩子" << endl;
//		}
//		if (root->left != nullptr) deleteNode(root->left, L, R);
//		if (root->right != nullptr) deleteNode(root->right, L, R);
//	}
//	void deleteLeftNode(TreeNode* parent) {
//		TreeNode* target = parent->left;
//		if (target == nullptr) return;
//		if (target->left == nullptr&&target->right == nullptr) {
//			//删除叶子节点
//			delete target;
//			parent->left = nullptr;
//		}
//		else if (target->left == nullptr) {
//			//左子树为空
//			parent->left = target->right;
//			delete target;
//		}
//		else if (target->right == nullptr) {
//			//右子树为空
//			parent->left = target->left;
//			delete target;
//		}
//		else {
//			//左右子树都不空
//			TreeNode* directSuccessor = target->right, *parent = target;
//			while (directSuccessor->left != nullptr) {
//				parent = directSuccessor;
//				directSuccessor = directSuccessor->left;
//			}
//			target->val = directSuccessor->val;
//			deleteLeftNode(parent);
//		}
//	}
//	void deleteRightNode(TreeNode* parent) {
//		TreeNode* target = parent->right;
//		if (target == nullptr) return;
//		if (target->left == nullptr&&target->right == nullptr) {
//			//删除叶子节点
//			delete target;
//			parent->right = nullptr;
//		}
//		else if (target->left == nullptr) {
//			//左子树为空
//			parent->right = target->right;
//			delete target;
//		}
//		else if (target->right == nullptr) {
//			//右子树为空
//			parent->right = target->left;
//			delete target;
//		}
//		else {
//			//左右子树都不空
//			TreeNode* directSuccessor = target->right, *parent = target;
//			while (directSuccessor->left != nullptr) {
//				parent = directSuccessor;
//				directSuccessor = directSuccessor->left;
//			}
//			target->val = directSuccessor->val;
//			deleteLeftNode(parent);
//		}
//	}
//};

//class Solution {
//public:
//  //不释放内存版本
//	TreeNode* trimBST(TreeNode* root, int L, int R) {
//		if (root == NULL) return NULL;
//		if (root->val < L) return trimBST(root->right, L, R);
//		if (root->val > R) return trimBST(root->left, L, R);
//		root->left = trimBST(root->left, L, R);
//		root->right = trimBST(root->right, L, R);
//		return root;
//	}
//};

//释放内存版本
TreeNode* trimBST(TreeNode* root, int L, int R, bool top = true) {
	if (!root)
		return root;
	root->left = trimBST(root->left, L, R, false);
	root->right = trimBST(root->right, L, R, false);
	if (root->val >= L && root->val <= R)
		return root;
	auto result = root->val < L ? root->right : root->left;
	if (!top)
		delete root;
	return result;
}