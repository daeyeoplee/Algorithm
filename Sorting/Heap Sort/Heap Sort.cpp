#include <iostream>

using namespace std;

int main() {
	int arr[]{ 9, 5, 3, 4, 1, 7, 6, 2, 8, 0 };

	for (int i = 9; i > 0; i--) { // MAX HEAP
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (arr[child] > arr[parent]) swap(arr[child], arr[parent]);
			else break;
			child = parent;
		} while (child != 0);
	}

	for (int end = 9; end > 0; end--) { // swap max value to last ele --> sorted
		swap(arr[end], arr[0]);
		int parent = 0;
		int child = parent * 2 + 1;
		while (child < end) {
			if (child + 1 < end && arr[child + 1] > arr[child])child++;
			if (arr[parent] < arr[child]) swap(arr[child], arr[parent]);
			else break;
			parent = child;
			child = parent * 2 + 1;
		}
	}

	for (auto e : arr) {
		cout << e << ' ';
	}
}
