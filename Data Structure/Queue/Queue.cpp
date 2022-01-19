#include <iostream>
#include <cassert>

/*
Queue using array(FIFO)
STL library <queue> exists
and for more efficent memory you can use Circular Queue
*/

using namespace std;

int q[100];
int f = 0;
int e = -1;

bool isEmpty() {
	return (f > e);
}

void push(int data) {
	q[++e] = data;
}

int peak() { // just return front ele
	assert(!isEmpty());
	return q[f];
}

int pop() { // return front ele and front move
	assert(!isEmpty());
	return q[f++];
}

bool isFull() { // Queue is Full
	if (e == 99) return true;
	return false;
}

int main() { // Same code with Stack you may check the difference between Stack and Queue
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