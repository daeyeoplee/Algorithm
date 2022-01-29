#include <iostream>
#include <vector>
#define NUM 12

/*
Segment Tree
O(logN) to edit or get sum
*/

using namespace std;

int a[] = { 1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5 };
int* tree = new int[4 * NUM];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right)return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
	if (index < start || index > end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
	init(0, NUM - 1, 1);
	cout << "sum 0 ~ 12: " << sum(0, NUM - 1, 1, 0, 12) << endl;
	cout << "sum 3 ~ 8 : " << sum(0, NUM - 1, 1, 3, 8) << endl;
	cout << "-5 to index 5" << endl;
	update(0, NUM - 1, 1, 5, -5);
	cout << "sum 3 ~ 8 : " << sum(0, NUM - 1, 1, 3, 8) << endl;
}