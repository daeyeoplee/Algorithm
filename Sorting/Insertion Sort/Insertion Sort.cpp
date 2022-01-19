#include <iostream>

/*
Insertion Sort
O(N^2)
swap when it is necessary --> when already sorted very efficient
assume sorted
*/

using namespace std;

int main() {
	int arr[]{ 9, 5, 3, 4, 1, 7, 6, 2, 8, 0 };
	for (int i = 1; i < 10; i++) { // asume 0 ~ i-1 is sorted
		for (int j = i; j > 0; j--) {
			if (arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
		}
	}

	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;
}
