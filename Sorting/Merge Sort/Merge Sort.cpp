#include <iostream>

/*
Merge Sort
always ensure O(NlogN)
but require additional memory
*/

using namespace std;

int sorted[10];

void merge(int list[], int left, int right) { // sorting while merge
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			sorted[k++] = list[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k++] = list[t];
		}
	}

	for (int t = left; t <= right; t++) {
		list[t] = sorted[t];
	}
}

void merge_sort(int list[], int left, int right) { // divide left &  right
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, right);
	}
}

int main() {
	int arr[]{ 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	merge_sort(arr, 0, 9);

	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;
}
