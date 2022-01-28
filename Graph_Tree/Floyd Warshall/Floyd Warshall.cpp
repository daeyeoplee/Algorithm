#include <iostream>

/*
Floyd Warshall Algorithm
find the shortest path each other nodes
keep update the shortest distance by checking the detour
can check all of the shortest paths --> O(N^3)
*/

using namespace std;

int num = 4;
int INF = 100000000;

int a[4][4] = {
	0, 5, INF, 8,
	7, 0, 9, INF,
	2, INF, 0, 4,
	INF, INF, 3, 6
};

void floydWarshall() {
	int d[4][4];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k : pivot
	for (int k = 0; k < num; k++) {
		// i : start
		for (int i = 0; i < num; i++) {
			// j : dest
			for (int j = 0; j < num; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	floydWarshall();
}
