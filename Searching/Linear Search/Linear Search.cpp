#include <iostream>
#define NUM 10

/*
Linear Search
O(N)
just search from first to last
doesn't have to be sorted
*/

using namespace std;

int a[] = { 8, 3, 5, 6, 1, 9, 6, 7, 2, 0 };
int target = 7;

int main() {
	for (int i = 0; i < NUM; i++) {
		if (a[i] == target) cout << (i + 1) << "번째에서 찾았습니다.";
	}
}