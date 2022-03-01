#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
int visited[1010];
int b[1010];
vector<vector<int>> node;
int dfs(int here) {
	//cout << "dfs 시작 here값은" << here << "\n";
	if (visited[here]) {
		//cout << "\n나여기 있어\n";
		return 0;
	}
	visited[here] = 1;
	for (int i = 0; i < node[here].size(); i++) {
		int there = node[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	//cout << "\n난 마지막에 끝남\n";
	return 0;
}
int bmatch() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		//cout << i << "번째 bmatch\n";
		memset(visited, 0, sizeof(visited));
		if (dfs(i))ret++;
		//cout << "\n 현재 b배열상황\n";
		//for (int i = 1; i <= n; i++)
		//	cout << b[i] << " ";
		//cout << "\n";
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &m);
	node.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int v, x;
		scanf("%d", &v);
		while (v--) {
			scanf("%d", &x);
			node[i].push_back(x);
		}
	}
	printf("%d", bmatch());
	return 0;
}


//출처: https://jason9319.tistory.com/149 [ACM-ICPC 상 탈 사람]