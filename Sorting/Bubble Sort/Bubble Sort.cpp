#include <iostream>

using namespace std;

int main() {
	int arr[]{ 9, 5, 3, 4, 1, 7, 6, 2, 8, 0 };
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}

	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;
}
