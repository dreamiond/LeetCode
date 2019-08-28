//leetcode427:Construct Quad Tree
/*
We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:

Given the 8 x 8 grid below, we want to construct the corresponding quad tree:



It can be divided according to the definition above:





The corresponding quad tree should be as following, where each node is represented as a (isLeaf, val) pair.

For the non-leaf nodes, val can be arbitrary, so it is represented as *.



Note:

N is less than 1000 and guaranteened to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

//class Solution {
//public:
//	Node* construct(vector<vector<int>>& grid) {
//		int left = 0, right = grid.size() - 1, top = 0, bottom = grid[0].size() - 1;
//		return recurse(left, right, top, bottom, grid);
//	}
//	Node* recurse(int left, int right, int top, int bottom,vector<vector<int>> &grid) {
//		Node *root = new Node();
//		if (allSame(left, right, top, bottom, grid)) {
//			//cout << left << " " << right << " " << top << " " << bottom << "是叶子节点" << endl;
//			root->val = grid[left][top];
//			root->isLeaf = true;
//			root->topLeft = nullptr; root->topRight = nullptr; root->bottomLeft = nullptr; root->bottomRight = nullptr;
//			return root;
//		}
//		else {
//			//cout << left << " " << right << " " << top << " " << bottom << "不是叶子节点" << endl;
//			root->isLeaf = false;
//			//cout << "左上" << endl;
//			root->topLeft = recurse(left, (left + right) / 2, top, (top + bottom) / 2, grid);
//			//cout << "右上" << endl;
//			root->topRight = recurse(1 + (left + right) / 2, right, top, (top + bottom) / 2, grid);
//			//cout << "左下" << endl;
//			root->bottomLeft = recurse(left, (left + right) / 2, 1 + (top + bottom) / 2, bottom, grid);
//			//cout << "右下" << endl;
//			root->topLeft = recurse(1 + (left + right) / 2, right, 1 + (top + bottom) / 2, bottom, grid);
//			return root;
//		}
//		
//	}
//	bool allSame(int left, int right, int top, int bottom, vector<vector<int>> &grid) {
//		int pivot = grid[left][top];
//		for (int i = left; i < right + 1; ++i) {
//			for (int j = top; j < bottom + 1; ++j) {
//				if (grid[i][j] != pivot) return false;
//			}
//		}
//		return true;
//	}
//};

class Solution {
private:
	Node* buildNode(vector<vector<int>>& grid, int x, int y, int length) {
		if (length == 1) {
			return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
		}

		int newLength = length / 2;
		Node* topLeft = buildNode(grid, x, y, newLength);
		Node* topRight = buildNode(grid, x, y + newLength, newLength);
		Node* botLeft = buildNode(grid, x + newLength, y, newLength);
		Node* botRight = buildNode(grid, x + newLength, y + newLength, newLength);

		if (topLeft->isLeaf && topRight->isLeaf && botRight->isLeaf && botLeft->isLeaf &&
			((topLeft->val && topRight->val && botLeft->val && botRight->val) ||
				!(topLeft->val || topRight->val || botLeft->val || botRight->val))) {
			bool val = topLeft->val;
			delete topLeft;
			topLeft = nullptr;
			delete topRight;
			topRight = nullptr;
			delete botLeft;
			botLeft = nullptr;
			delete botRight;
			botRight = nullptr;
			return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
		}
		return new Node(true, false, topLeft, topRight, botLeft, botRight);
	}
public:
	Node* construct(vector<vector<int>>& grid) {
		int N = grid.size();
		if (N == 0) {
			return nullptr;
		}
		return buildNode(grid, 0, 0, N);
	}
};

//void main() {
//	//vector<vector<int>> v = { {1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0} };
//	//vector<vector<int>> v = { {1,1},{1,0} };
//	vector<vector<int>> v = { {1, 1, 0, 0, 0, 0, 0, 0}, { 1, 1, 0, 0, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0, 0, 1, 1 }, { 1, 1, 0, 0, 0, 0, 1, 1 }, { 0, 0, 0, 0, 0, 0, 1, 1 }, { 0, 0, 0, 0, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 0, 0 }, { 1, 1, 1, 1, 1, 1, 0, 0 }};
//	Solution sol;
//	sol.construct(v);
//}