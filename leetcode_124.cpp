//leetcode124:Binary Tree Maximum Path Sum
/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

1
/ \
2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

-10
/ \
9  20
/  \
15   7

Output: 42
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//update the val of each node of the tree bottom-up,
//the new val of TreeNode *x stands for the max sum started from any node in subtree x and ended in x,
//mataining the re for result in traversal at the same time.
/*
使用bottom-up可以有效节约重复计算
对于某个节点，可能的最大路径和只能是下面情况中的一种

max(left subtree) + node
max(right subtree) + node
max(left subtree) + max(right subtree) + node
node
*/
class Solution {
	int maxToRoot(TreeNode *root, int &re) {
		if (!root) return 0;
		int l = maxToRoot(root->left, re);
		int r = maxToRoot(root->right, re);
		if (l < 0) l = 0;
		if (r < 0) r = 0;
		if (l + r + root->val > re) re = l + r + root->val;
		return root->val += max(l, r);
	}
public:
	int maxPathSum(TreeNode *root) {
		int max = -2147483648;
		maxToRoot(root, max);
		return max;
	}
};