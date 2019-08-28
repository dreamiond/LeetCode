//leetcode637:Average of Levels in Binary Tree
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
3
/ \
9  20
/  \
15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		vector<double> res;
		while (!q.empty()) {
			double sum = 0, count = 0;
			int length = q.size();
			for (int i = 0; i < length; i++) {
				sum += q.front()->val;
				count++;
				TreeNode* temp = q.front();
				q.pop();
				if (temp->left != nullptr) q.push(temp->left);
				if (temp->right != nullptr) q.push(temp->right);
			}
			res.push_back(sum / count);
		}
		return res;
	}
};

//void main() {
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->left->left = new TreeNode(15);
//	root->left->right = new TreeNode(7);
//	Solution sol;
//	vector<double> v = sol.averageOfLevels(root);
//	for (auto i : v) {
//		cout<<i<<endl;
//	}
//}