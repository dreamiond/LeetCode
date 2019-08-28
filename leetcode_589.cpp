//leetcode589:N-ary Tree Preorder Traversal
/*
Given an n-ary tree, return the preorder traversal of its nodes' values.


For example, given a 3-ary tree:




Return its preorder traversal as: [1,3,5,6,2,4].
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	//vector<int> preorder(Node* root) {
	//	vector<int> res;
	//	recursivePreorder(root, res);
	//	return res;
	//}

	//void recursivePreorder(Node* root, vector<int>& res) {
	//	if (root == nullptr) return;
	//	res.push_back(root->val);
	//	for (auto child : root->children) {
	//		recursivePreorder(child, res);
	//	}
	//}
	vector<int> preorder(Node* root) {
		if (root == nullptr) return{};
		stack<Node*> stk;
		vector<int> res;
		stk.push(root);
		while (!stk.empty()) {
			Node* temp = stk.top();
			stk.pop();
			for (int i = temp->children.size() - 1; i >= 0; i--) {
				stk.push(temp->children[i]);
			}
			res.push_back(temp->val);
		}
		return res;
	}
};