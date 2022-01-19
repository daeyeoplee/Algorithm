#include <iostream>

/*
Quick sort
normally O(NlogN)
but when it's already sorted O(N^2)
using pivot -> choosing appropriate pivot value is important
divide and conquer alogirhtm
*/

using namespace std;

void qsort(int list[], int left, int right) {
	if (left >= right) return;

	int pivot = left;
	int i = left+1, j = right;
	while (i <= j) { // less than pivot ~~ pivot ~~ greater than pivot
		while (i <= right && list[i] <= list[pivot]) i++;

		while (j > left && list[j] >= list[pivot]) j--;

		if (i <= j) swap(list[i], list[j]);
		else swap(list[j], list[pivot]);
	}

	qsort(list, left, j - 1); // divide
	qsort(list, j + 1, right); // divide
}

int main() {
	int arr[]{ 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	qsort(arr, 0, 9);

	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;
}
