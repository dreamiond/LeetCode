//leetcode919:Complete Binary Tree Inserter
/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.


Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]


Note:

The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_set>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {
private:
	vector<TreeNode*> cbt;
public:
	CBTInserter(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *tmp = q.front();
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
			cbt.push_back(tmp);
			q.pop();
		}
	}

	int insert(int v) {
		TreeNode *tmp = new TreeNode(v);
		cbt.push_back(tmp);
		TreeNode *root = cbt[cbt.size() / 2 - 1];
		if (root->left == nullptr) root->left = tmp;
		else root->right = tmp;
		return root->val;
	}

	TreeNode* get_root() {
		return cbt[0];
	}
};

/**
* Your CBTInserter object will be instantiated and called as such:
* CBTInserter* obj = new CBTInserter(root);
* int param_1 = obj->insert(v);
* TreeNode* param_2 = obj->get_root();
*/


//void upHelper(vector<int> nums, int change, int &res, int i = 1) {
//	if (i == nums.size()) {
//		res = min(change, res);
//		return;
//	}
//	if (nums[i] >= nums[i - 1]) upHelper(nums, change, res, i + 1);
//	else {
//		change += nums[i - 1] - nums[i];
//		int tmp = nums[i - 1];
//		nums[i - 1] = nums[i];
//		if(i==1 || i != 1 && nums[i] < nums[i-2]) upHelper(nums, change, res, i + 1);
//		else upHelper(nums, change, res, i - 1);
//		nums[i - 1] = tmp;
//		nums[i] = nums[i - 1];
//		upHelper(nums, change, res, i + 1);
//	}
//}
//void downHelper(vector<int> nums, int change, int &res, int i = 1) {
//	if (i == nums.size()) {
//		res = min(change, res);
//		return;
//	}
//	if (nums[i] <= nums[i - 1]) downHelper(nums, change, res, i + 1);
//	else {
//		change += nums[i] - nums[i - 1];
//		int tmp = nums[i - 1];
//		nums[i - 1] = nums[i];
//		if(i == 1 || i != 1 && nums[i] > nums[i-2]) downHelper(nums, change, res, i + 1);
//		else downHelper(nums, change, res, i - 1);
//		nums[i - 1] = tmp;
//		nums[i] = nums[i - 1];
//		downHelper(nums, change, res, i + 1);
//	}
//}
//
//int wht(vector<int> nums) {
//	if (nums.size() == 0 || nums.size() == 1) return 0;
//	int up = INT_MAX;
//	int down = INT_MAX;
//	upHelper(nums, 0, up);
//	downHelper(nums, 0, down);
//	return min(up, down);
//}
//
//
//
//int main() {
//	vector<int> v{ 1,2,7,2,5 };
//	cout << wht(v);
//	return 0;
//}