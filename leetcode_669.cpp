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
//			//ɾ��root
//			if (root->left == nullptr) {
//				//������Ϊ��
//				cout << "ɾ��"<<root->val<<"������root���Һ���" << endl;
//				TreeNode* temp = root->right;
//				delete root;
//				return temp;
//			}
//			else if (root->right == nullptr) {
//				//������Ϊ��
//				cout << "ɾ��" << root->val << "������root������" << endl;
//				TreeNode* temp = root->left;
//				delete root;
//				return temp;
//			}
//			else {
//				//��������������
//				TreeNode* directSuccessor = root->right, *parent = root;
//				while (directSuccessor->left != nullptr) {
//					parent = directSuccessor;
//					directSuccessor = directSuccessor->left;
//				}
//				root->val = directSuccessor->val;
//				cout << "ɾ��" << root->val << "����"<<directSuccessor->val<<"����" << endl;
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
//			cout << "ɾ��" << root->val << "������" << endl;
//			deleteLeftNode(root);
//		}
//		while (root->right != nullptr && (root->right->val<L || root->right->val>R)) {
//			deleteRightNode(root);
//			cout << "ɾ��" << root->val << "���Һ���" << endl;
//		}
//		if (root->left != nullptr) deleteNode(root->left, L, R);
//		if (root->right != nullptr) deleteNode(root->right, L, R);
//	}
//	void deleteLeftNode(TreeNode* parent) {
//		TreeNode* target = parent->left;
//		if (target == nullptr) return;
//		if (target->left == nullptr&&target->right == nullptr) {
//			//ɾ��Ҷ�ӽڵ�
//			delete target;
//			parent->left = nullptr;
//		}
//		else if (target->left == nullptr) {
//			//������Ϊ��
//			parent->left = target->right;
//			delete target;
//		}
//		else if (target->right == nullptr) {
//			//������Ϊ��
//			parent->left = target->left;
//			delete target;
//		}
//		else {
//			//��������������
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
//			//ɾ��Ҷ�ӽڵ�
//			delete target;
//			parent->right = nullptr;
//		}
//		else if (target->left == nullptr) {
//			//������Ϊ��
//			parent->right = target->right;
//			delete target;
//		}
//		else if (target->right == nullptr) {
//			//������Ϊ��
//			parent->right = target->left;
//			delete target;
//		}
//		else {
//			//��������������
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
//  //���ͷ��ڴ�汾
//	TreeNode* trimBST(TreeNode* root, int L, int R) {
//		if (root == NULL) return NULL;
//		if (root->val < L) return trimBST(root->right, L, R);
//		if (root->val > R) return trimBST(root->left, L, R);
//		root->left = trimBST(root->left, L, R);
//		root->right = trimBST(root->right, L, R);
//		return root;
//	}
//};

//�ͷ��ڴ�汾
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