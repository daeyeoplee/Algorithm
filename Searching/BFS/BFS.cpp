#include <iostream>
#include <queue>
#include <vector>
/*
BFS using STL <queue>
Breadth First Search
search neareast nodes first
use for shortest path
visiting order can differ
*/

using namespace std;

queue<int> q;
vector<vector<int>> graph;
bool vis[7];

void BFS(int start) {
	q.push(start);
	vis[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!vis[next]) {
				q.push(next);
				vis[next] = true;
			}
		}
	}
}

int main() { // Same graph with DFS you may check out difference between BFS and DFS
	graph.resize(8);
	// 1 & 2
	graph[1].push_back(2);
	graph[2].push_back(1);
	// 1 & 3
	graph[1].push_back(3);
	graph[3].push_back(1);
	// 2 & 3
	graph[2].push_back(3);
	graph[3].push_back(2);
	// 2 & 4
	graph[2].push_back(4);
	graph[4].push_back(2);
	// 2 & 5
	graph[2].push_back(5);
	graph[5].push_back(2);
	// 3 & 6
	graph[3].push_back(6);
	graph[6].push_back(3);
	// 3 & 7
	graph[3].push_back(7);
	graph[7].push_back(3);
	// 4 & 5
	graph[4].push_back(5);
	graph[5].push_back(4);
	// 6 & 7
	graph[6].push_back(7);
	graph[7].push_back(6);
	BFS(1);
}

/*
graph
	    1
	  /   \
	 2 --- 3
	/ \   / \
   4 - 5 6 - 7
*/
