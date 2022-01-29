#include <iostream>

/*
Binary Search
O(logN)
data must have to be sorted
check if data is larger or lesser
--> makes range into half
*/

using namespace std;

// sorted array
int a[] = { 1, 3, 5, 7, 9, 11, 14, 15, 18, 19, 25, 28 };
int target = 7;

int B_search(int start, int end, int target) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (target == a[mid]) return mid;
	else if (a[mid] > target) B_search(start, mid - 1, target);
	else B_search(mid + 1, end, target);
}

int main() {
	int result = B_search(0, 11, target);
	if (result != -1) cout << (result + 1) << "번째에서 찾았습니다.";
}