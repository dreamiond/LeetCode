//leetcode155:Min Stack
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>

using namespace std;

class MinStack {
private:
	stack<int> s;
	stack<int> mins;
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		s.push(x);
		if (mins.empty() || x <= getMin()) mins.push(x);
	}

	void pop() {
		if (s.top() == mins.top()) mins.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return mins.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

