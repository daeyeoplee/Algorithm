#include <iostream>
#define NUM 6

/*
Index Tree
edit or get sum O(logN)
have better memory efficiency than Segment Tree
last bit(i & -i) means how many values does i(index) contains
*/

using namespace std;

int tree[NUM];

int sum(int i) {
	int result = 0;
	while (i > 0) {
		result += tree[i];
		i -= (i & -i);
	}
	return result;
}

void update(int i, int dif) {
	while (i <= NUM) {
		tree[i] += dif;
		i += (i & -i);
	}
}

int getSection(int start, int end) {
	return sum(end) - sum(start - 1);
}

int main() {
	update(1, 1);
	update(2, 2);
	update(3, 3);
	update(4, 4);
	update(5, 5);
	cout << getSection(2, 5) << endl;
	update(3, -2);
	cout << getSection(2, 5) << endl;
	update(5, 2);
	cout << getSection(2, 5) << endl;
	cout << getSection(1, 5) << endl;
}