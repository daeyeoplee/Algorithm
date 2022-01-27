#include <iostream>
#include <algorithm>
#include <vector>

/*
Kruskal Algorithm
find out MST(minimum spanning tree)
sort the edges' cost --> choose minimum costs
if(cycle does not happen) <-- Union Find Algo

PS.
using the same code with Union_Find for union find
if you don't aware of this algo check it out in Union_find.cpp

if you wanna check out the graph visit
https://blog.naver.com/ndb796/221230994142
*/

using namespace std;

int getParent(int par[], int c) {
	if (par[c] == c) return c;
	return par[c] = getParent(par, par[c]);
}

void unionParent(int par[], int a, int b) {
	a = getParent(par, a);
	b = getParent(par, b);
	if (a > b) swap(a, b);
	par[b] = a;
}

bool findParent(int par[], int a, int b) {
	if (getParent(par, a) == getParent(par, b)) return true;
	else return false;
}

class Edge {
public:
	pair<int, int> node;
	int dis;
	Edge(int a, int b, int dis) {
		this->node.first = a;
		this->node.second = b;
		this->dis = dis;
	}
	// for using sort in <algorithm>
	bool operator < (Edge& e) {
		return this->dis < e.dis;
	}
};

int main() {
	int n = 7;
	int m = 11;

	// insert the Edges
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// sort the edge with the cost
	sort(v.begin(), v.end());

	int par[8];
	for (int i = 0; i <= n; i++) par[i] = i;

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// cycle doesn't happen
		if (!findParent(par, v[i].node.first, v[i].node.second)) {
			sum += v[i].dis;
			unionParent(par, v[i].node.first, v[i].node.second);
		}
	}
	
	cout << sum;
}