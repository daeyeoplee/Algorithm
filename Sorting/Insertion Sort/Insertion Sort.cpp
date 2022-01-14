#include <iostream>

using namespace std;

int main() {
	int arr[]{ 9, 5, 3, 4, 1, 7, 6, 2, 8, 0 };
	for (int i = 1; i < 10; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
		}
	}

	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;
}
