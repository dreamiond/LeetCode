//leetcode1106:Parsing A Boolean Expression
/*
Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...


Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false


Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
private:
	char calculate(vector<char> v, char op) {
		if (op == '!') {
			if (v[0] == 't') return 'f';
			else return 't';
		}
		else if (op == '|') {
			for (auto c : v) {
				if (c == 't') return 't';
			}
			return 'f';
		}
		else{
			for (auto c : v) {
				if (c == 'f') return 'f';
			}
			return 't';
		}
	}
public:
	bool parseBoolExpr(string expression) {
		stack<char> helper;
		for (auto c : expression) {
			if (c == ',') continue;
			if (c == ')') {
				vector<char> v{};
				while (helper.top() != '(') {
					v.push_back(helper.top());
					helper.pop();
				}
				helper.pop();
				char op = helper.top();
				helper.pop();
				helper.push(calculate(v, op));
			}
			else {
				helper.push(c);
			}
		}
		if (helper.top() == 'f') return false;
		else return true;
	}
};

//int main() {
//	Solution sol;
//	sol.parseBoolExpr("&(t,f)");
//	return 0;
//}