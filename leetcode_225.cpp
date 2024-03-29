//leetcode225:Implement Stack using Queues
/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <queue>

using namespace std;

class MyStack {
private:
	queue<int> a, b;
	int n, topNum;
public:
	/** Initialize your data structure here. */
	MyStack() {
		n = 0;
		topNum = 0;
	}

	/** Push element x onto stack. */
	void push(int x) {
		a.push(x);
		++n;
		topNum = x;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		for (int i = 0; i < n - 1; ++i) {
			b.push(a.front());
			a.pop();
		}
		int res = a.front();
		a.pop();
		--n;
		for (int i = 0; i < n - 1; ++i) {
			a.push(b.front());
			b.pop();
		}
		topNum = b.front();
		a.push(b.front());
		b.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return topNum;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return n == 0;
	}
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/