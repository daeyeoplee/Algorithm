#include <iostream>
#include <stack>
#include <vector>
/*
DFS using STL <stack>
Depth First Search
using recursive function is avaiable
Does not ensure shortest path
visiting order can differ
*/

using namespace std;

stack<int> s;
vector<vector<int>> graph;
bool vis[7];

void BFS(int start) { // Stack ver.
	s.push(start);
	vis[start] = true;
	while (!s.empty()) {
		int now = s.top();
		s.pop();
		cout << now << ' ';
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!vis[next]) {
				s.push(next);
				vis[next] = true;
			}
		}
	}
}

void bfs(int now) { // Recursive ver.
	vis[now] = true;
	cout << now << ' ';
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (!vis[next]) bfs(next);
	}
}

int main() { // Same graph with BFS you may check out difference between BFS and DFS
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
	
	//BFS(1);
	bfs(1);
}

/*
graph
		1
	  /   \
	 2 --- 3
	/ \   / \
   4 - 5 6 - 7
*/
