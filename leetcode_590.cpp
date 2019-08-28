//leetcode590:N-ary Tree Postorder Traversal
/*
Given an n-ary tree, return the postorder traversal of its nodes' values.


For example, given a 3-ary tree:




Return its postorder traversal as: [5,6,3,2,4,1].


Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <list>

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
	vector<int> postorder(Node* root) {
		if (root == nullptr) return vector<int>();
		stack<Node*> stk;
		stk.push(root);
		list<int> res;
		while (!stk.empty()) {
			res.push_front(stk.top()->val);
			Node* temp = stk.top();
			stk.pop();
			for (auto i : temp->children) {
				stk.push(i);
			}
		}
		return vector<int>(res.begin(), res.end());
	}
};