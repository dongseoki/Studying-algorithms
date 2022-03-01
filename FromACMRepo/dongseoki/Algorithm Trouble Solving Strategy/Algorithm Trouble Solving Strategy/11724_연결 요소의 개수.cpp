#include <iostream>
#include <vector>
using namespace std;
int N, M;
int ans = 0;
void dfs(int here, vector<bool> &visited, vector<vector<int>> &adjlist) {
		for (int i = 0; i < adjlist[here].size(); i++) {
			int there = adjlist[here][i];
			if (visited[there] == false) {
				visited[there] = true;
				dfs(there, visited, adjlist);
			}
		}
}
int main(void) {
	
	cin >> N;
	cin >> M;
	// start from idex 0;
	vector<bool> visited(N, false);
	vector<vector<int>> adjlist(N, vector<int>());
	for (int i = 0; i < M; i++) {
		int num = 0;
		int num2;
		cin >> num;
		cin >> num2;
		adjlist[num-1].push_back(num2-1);
		adjlist[num2 - 1].push_back(num - 1);
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			ans++;
			dfs(i,visited,adjlist);
		}

	}
	cout << ans<<"\n";

}