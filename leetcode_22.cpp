//leetcode22:Generate Parentheses
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_set>

using namespace std;


//排列组合做法，会time limit exceed

//class Solution {
//private:
//	vector<char> parentheses;
//	vector<vector<int>> allPossibleCombination;
//public:
//	vector<string> generateParenthesis(int n) {
//		for (int i = 0; i < n; ++i) {
//			parentheses.push_back('(');
//			parentheses.push_back(')');
//		}
//		constructCombination({});
//		unordered_set<string> res;
//		for (auto com : allPossibleCombination) {
//			string tmp = checkValidAndJoint(com);
//			if (tmp != "") res.insert(tmp);
//		}
//		vector<string> vs(res.begin(), res.end());
//		return vs;
//	}
//	void constructCombination(vector<int> combination) {
//		if (combination.size() == parentheses.size()) {
//			allPossibleCombination.emplace_back(combination);
//			return;
//		}
//		for (int i = 0; i < parentheses.size(); ++i) {
//			//如果combination内没有i
//			if (find(combination.begin(), combination.end(), i) == combination.end()) {
//				combination.push_back(i);
//				constructCombination(combination);
//				combination.pop_back();
//			}
//		}
//	}
//	string checkValidAndJoint(vector<int> combination) {
//		stack<char> s;
//		string res = "";
//		for (auto i : combination) {
//			res += parentheses[i];
//			if (parentheses[i] == '(') {
//				s.push('(');
//			}
//			else {
//				if (!s.empty() && s.top() == '(') {
//					s.pop();
//				}
//				else {
//					return "";
//				}
//			}
//		}
//		return res;
//	}
//};

//n是剩余的"("，m是还能加的")"
//类似操作系统中的锁，m控制了"("与")"的同步关系

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addingpar(res, "", n, 0);
		return res;
	}
	void addingpar(vector<string> &v, string str, int n, int m) {
		if (n == 0 && m == 0) {
			v.emplace_back(str);
			return;
		}
		if (n > 0) {
			addingpar(v, str + "(", n - 1, m + 1);
		}
		if (m > 0) {
			addingpar(v, str + ")", n, m - 1);
		}
	}
};