#include <iostream>

/*
Uninon Find Algorithm
in a graph find the parent node
--> if each node's parent is same
	they are connected
*/

using namespace std;

// return the parent node
int getParent(int par[], int c) {
	if (par[c] == c) return c;
	return par[c] = getParent(par, par[c]);
}

// connect a & b
void unionParent(int par[], int a, int b) {
	a = getParent(par, a);
	b = getParent(par, b);
	if (a > b) swap(a, b);
	par[b] = a;
}

// if a & b have the same parent node
bool findParent(int par[], int a, int b) {
	if (getParent(par, a) == getParent(par, b)) return true;
	else return false;
}

int main() {
	int par[11];
	for (int i = 0; i <= 10; i++) {
		par[i] = i;
	}
	// connect nodes
	unionParent(par, 1, 2);
	unionParent(par, 2, 3);
	unionParent(par, 3, 4);
	unionParent(par, 5, 6);
	unionParent(par, 6, 7);
	unionParent(par, 7, 8);
	cout << "Dose 1 and 5 is Connectend? " << findParent(par, 1, 5) << "\n";
	unionParent(par, 1, 5);
	cout << "Dose 1 and 5 is Connectend? " << findParent(par, 1, 5) << "\n";
	
}