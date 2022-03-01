#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
int M;
int V; // 1부터..
vector<vector<int>> al(10000, vector<int>());
vector<bool> visited(10000, false);


void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		// 내용
		cout << u +1 << " ";

		//
		
		int sz = al[u].size();
		for (int i = 0; i < sz; i++) {
			int v = al[u][i];
			if (visited[v] == false) {
				q.push(v);
				visited[v] = true;
			}
		}

	}

}

int main(void) {
	cin >> N;
	cin >> M;
	cin >> V;
	V = V - 1;
	for (int i = 0; i < M; i++) {
		int v;
		int u;
		cin >> v;
		cin >> u;
		v--;
		u--;
		al[u].push_back(v);
		al[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		sort(al[i].begin(), al[i].end());
	}



	bfs(V);

}