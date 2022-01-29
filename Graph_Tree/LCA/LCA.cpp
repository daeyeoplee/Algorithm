#include <iostream>
#include <vector>
#define MAX 1001
#define LOG 11

/*
LCA
(Lowest Common Ancestor)
find the parent node of each level
*/

using namespace std;

int n, m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];

void dfs(int x, int depth) {
	c[x] = true;
	d[x] = depth;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		parent[y][0] = x;
		dfs(y, depth + 1);
	}
}

void setParent() {
	dfs(0, 0);
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x, int y) {
	if (d[x] > d[y]) swap(x, y);

	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

void link(int x, int y) {
	a[x].push_back(y);
	a[y].push_back(x);
}

int main() {
	n = 21;
	link(0, 1);
	link(0, 2);
	link(1, 3);
	link(1, 4);
	link(2, 5);
	link(2, 6);
	link(3, 7);
	link(3, 8);
	link(4, 9);
	link(4, 10);
	link(4, 11);
	link(8, 12);
	link(8, 13);
	link(9, 14);
	link(10, 15);
	link(13, 16);
	link(13, 17);
	link(14, 18);
	link(15, 19);
	link(17, 20);
	setParent();
	cout << "5 & 7 LCA: " << LCA(5, 7) << endl;
	cout << "15&20 LCA: " << LCA(15, 20) << endl;
	cout << "16&17 LCA: " << LCA(16, 17) << endl;
	cout << "10& 9 LCA: " << LCA(10, 9) << endl;
	cout << "3 &17 LCA: " << LCA(3, 17) << endl;

}