#include <iostream>
#include <vector>
#include <cassert>

/*
Stack using vector(LIFO)
array is also possible
STL Library <stack> exists
*/

using namespace std;

vector<int> stack;

bool isEmpty() { // check if stack is empty
	return stack.empty();
}

void push(int data) { // push data
	stack.push_back(data);
}

int peak() { // check what's on the top(not pop)
	assert(!isEmpty());
	return stack.back();
}

int pop() { // return top and pop top data
	assert(!isEmpty());
	int data = stack.back();
	stack.pop_back();
	return data;
}

// isFull() if you need

int main() { // Same code with Queue you may check the difference between Stack and Queue
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	while (!isEmpty()) {
		cout << pop() << ' ';
	}
}