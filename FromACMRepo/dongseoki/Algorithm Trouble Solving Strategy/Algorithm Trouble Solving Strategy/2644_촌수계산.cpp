#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int x, y;
int ans = 0;
// 1. 자료구조 선언
vector<int> edge[10001];
int dist[10001];
// 2. 초기화
void initVisit()
{
	for (int i = 0; i < 10001; i++)
		dist[i] = -1;
}

void bfs(int s, int e, vector<bool>& visited, vector<vector<int>>& adjlist)
{
	queue<int> q;
	int now, k, next;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		if (now == e)
			return;

		for (k = 0; k < adjlist[now].size(); k++) {
			next = adjlist[now][k];
			if (dist[next] == -1) {
				dist[next] = dist[now] + 1;
				/*if (next == e)
					return;*/
				q.push(next);
			}
		}
	}
}

void dfs(int here, int value,vector<bool>& visited, vector<vector<int>>& adjlist) {
	
	if (here == y) {
		cout << value;
		cout << "\n";
		exit(0);
	}
	for (int i = 0; i < adjlist[here].size(); i++) {
		int there = adjlist[here][i];
		if (visited[there] == false) {
			visited[there] = true;
			dfs(there,value+1, visited, adjlist);
		}
	}
}
int main(void) {

	cin >> N;
	cin >> x;
	x -= 1;
	cin >> y;
	y -= 1;
	cin >> M;
	// start from idex 0;
	vector<bool> visited(N, false);
	vector<vector<int>> adjlist(N, vector<int>());
	for (int i = 0; i < M; i++) {
		int num = 0;
		int num2;
		cin >> num;
		cin >> num2;
		adjlist[num - 1].push_back(num2 - 1);
		adjlist[num2 - 1].push_back(num - 1);
	}


	//visited[x] = true;
	////ans++;
	//dfs(x, 0,visited, adjlist);



	initVisit();
	bfs(x, y, visited, adjlist);
	printf("<%d>\n", dist[y]);



	cout << "-1"<< "\n";

}