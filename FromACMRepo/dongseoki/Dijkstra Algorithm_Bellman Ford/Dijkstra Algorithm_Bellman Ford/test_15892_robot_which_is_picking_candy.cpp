#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

struct MaxFlow {
	struct Edge {
		int to, cap;
		Edge* rev;
		Edge(int t, int c) :to(t), cap(c), rev(NULL) {}
	};

	int n, src, sink;
	vector<vector<Edge*>> p;
	vector<int> level, work;
	MaxFlow(int n, int s, int t) :n(n), src(s), sink(t) {
		p.resize(n + 1);
	}
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		p[u].push_back(ori);
		p[v].push_back(rev);
	}

	int flow() {
		int ans = 0;
		while (bfs()) {
			work = vector<int>(n + 1);
			int f = 0;
			while (f = dfs(src, INF))
				ans += f;
		}
		return ans;
	}
	bool bfs() {
		level = vector<int>(n + 1, -1);
		queue<int> q;
		q.push(src);
		level[src] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto e : p[now]) {
				int next = e->to;
				int ncap = e->cap;
				if (ncap > 0 && level[next] == -1) {
					level[next] = level[now] + 1;
					q.push(next);
				}
			}
		}
		return level[sink] != -1;
	}

	int dfs(int now, int c) {
		if (now == sink) {
			return c;
		}
		for (int& i = work[now]; i < p[now].size(); i++) {
			auto e = p[now][i];
			int next = e->to;
			int ncap = e->cap;

			if (level[next] == level[now] + 1 && ncap > 0) {
				int f = dfs(next, min(ncap, c));
				if (f) {
					e->cap -= f;
					e->rev->cap += f;
					return f;
				}
			}
		}
		return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	MaxFlow mf(n, 1, n); // 길이 source sink 순이다.
	for (int i = 0; i < m; i++) {
		int u, v, cap;
		cin >> u >> v >> cap;
		mf.add_edge(u, v, cap); // 시작 , 끝 사탕.
		mf.add_edge(v, u, cap);
	}
	cout << mf.flow();
}