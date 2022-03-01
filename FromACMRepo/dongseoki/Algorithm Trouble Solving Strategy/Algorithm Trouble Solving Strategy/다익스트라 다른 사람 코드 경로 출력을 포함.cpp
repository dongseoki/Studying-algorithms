#include <cstdio>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <utility>
#define MAX_VALUE -987654321
using namespace std;
int n, m, s;
class Vertex {
public:
	int index;
	int dist;
	int post = 0;
	Vertex(int index, int dist, int post) :index(index), dist(dist), post(post) {
	}
	Vertex(int index) :index(index) {
		dist = MAX_VALUE;
	}
	void setDist(int d) {
		dist = d;
	}
	bool operator >(const Vertex& v) const {
		return dist > v.dist;
	}
	bool operator <(const Vertex& v) const {
		return dist < v.dist;
	}
};
class Graph {
public:
	int n = 0;
	vector<Vertex> vt;
	vector<vector<pair<int, int> > > adj;
	priority_queue<Vertex > pq;
	map<int, pair<int, int> > m;

	void addVertex(int index, int dist) {
		vt.push_back(Vertex(index, dist, index));
		n = vt.size();
		adj.resize(n + 1);
	}
	void addVertex(int index) {
		vt.push_back(Vertex(index));
		n = vt.size();
		adj.resize(n);
	}
	void addAdj(int u, int v, int w) {
		adj[u - 1].push_back(make_pair(v, w));
	}
	void setStart(int index) {
		vt[index - 1].setDist(0);
		vt[index - 1].post = index;
	}
	void dijkstra(int s) {
		vector<int> dist(n, -1 * MAX_VALUE);
		dist[s - 1] = 0;
		setStart(s);
		for (int i = 0; i < n; i++) {
			pq.push(vt[i]);
		}
		m.insert(make_pair(s, make_pair(0, -1)));
		while (!pq.empty()) {
			int index = pq.top().index - 1;
			int cost = -1 * pq.top().dist; pq.pop();
			if (dist[index] < cost) continue;
			for (int i = 0; i < adj[index].size(); i++) {
				int n = adj[index][i].first;
				int v = adj[index][i].second;
				if (dist[n - 1] > dist[index] + v) {
					dist[n - 1] = dist[index] + v;
					Vertex newVt = Vertex(n, -dist[n - 1], index + 1);
					pq.push(newVt);
					m[n] = make_pair(dist[n - 1], index + 1);

				}
			}
		}

		printf("인덱스 별 최단 경로 길이\n");
		for (int i = 0; i < n; i++) {
			printf(dist[i] != -1 * MAX_VALUE ? "%d " : "INF ", dist[i]);
		}
		printf("\n\n인덱스 - 최단 경로 - 이전 정점\n");
		for (int i = 1; i <= m.size(); i++) {
			printf("%d - %d - %d\n", i, m[i].first, m[i].second);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%d까지 경로 : ", i);
			if (dist[i - 1] != -MAX_VALUE) {
				stack<int> st;
				int next = m[i].second;
				while (next != -1) {
					st.push(next);
					next = m[next].second;
				}
				while (!st.empty()) {
					printf("%d - ", st.top());
					st.pop();
				}
				printf("%d\n", i);
			}
		}
	}
};
int main() {
	scanf("%d %d %d", &n, &m, &s);
	Graph gp;
	for (int i = 0; i < n; i++) {
		gp.addVertex(i + 1);
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		gp.addAdj(u, v, w);
	}
	gp.dijkstra(s);
}