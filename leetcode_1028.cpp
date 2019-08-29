//leetcode1028:Recover a Tree From Preorder Traversal
/*
We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.



Example 1:



Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:



Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]


Example 3:



Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]


Note:

The number of nodes in the original tree is between 1 and 1000.
Each node will have a value between 1 and 10^9.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include <sstream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
	int val;
	int depth;
	Node(int val,int depth) : val(val),depth(depth) {}
};

class Solution {
private:
	vector<Node> string2NodeVec(string s) {
		s = "-" + s + "-";
		vector<Node> res;
		int firstDash = 0, lastDash = 0, lastNum = 0;
		for (int i = 1; i < s.size() - 1; ++i) {
			if (s[i] == '-' && s[i - 1] != '-') {
				firstDash = i;
			}
			if (s[i] == '-' && s[i + 1] != '-') {
				lastDash = i;
			}
			else if (s[i] != '-' && s[i + 1] == '-') {
				lastNum = i;
				stringstream ss;
				ss << s.substr(lastDash + 1, lastNum - lastDash);
				int val = 0;
				ss >> val;
				res.emplace_back(Node(val, lastDash - firstDash + 1));
			}
		}
		res[0].depth = 0;
		return res;
	}
public:
	TreeNode* recoverFromPreorder(string S) {
		if (S.empty()) return nullptr;
		vector<Node> v = string2NodeVec(S);

		stack<TreeNode*> treeNodeStack;
		stack<int> depthStack;
		TreeNode *res = new TreeNode(v[0].val);
		treeNodeStack.push(res);
		depthStack.push(v[0].depth);
		for (int i = 1; i < v.size();) {
			if (v[i].depth > depthStack.top()) {
				TreeNode *tmp = new TreeNode(v[i].val);
				if (treeNodeStack.top()->left != nullptr) {
					treeNodeStack.top()->right = tmp;
				}
				else {
					treeNodeStack.top()->left = tmp;
				}
				treeNodeStack.push(tmp);
				depthStack.push(v[i].depth);
				++i;
			}
			else {
				while (v[i].depth <= depthStack.top()) {
					treeNodeStack.pop();
					depthStack.pop();
				}
			}
		}
		return res;
	}
};

int main() {
	string s("1-2--3--4-5--6--7");
	Solution sol;
	sol.recoverFromPreorder(s);
}