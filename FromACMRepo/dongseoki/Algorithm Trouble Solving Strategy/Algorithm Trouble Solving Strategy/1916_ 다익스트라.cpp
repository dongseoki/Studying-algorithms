#include <iostream>
#include <vector>
#include <limits>
#include <utility>//pair 포함 헤더
#include <queue>

using namespace std;

int V;
int E;
vector<vector<pair<int, int>>> adjlist;


void print_shortest_path(vector<int> & dist, vector<int>& prev, int src) {
	for (int i = 1; i < (V + 1); i++) {
		cout << i << "까지 경로 : (최단거리="<<dist[i]<<")";
		int next = i;
		while (1) {
			// 탈출 조건
			if (prev[next] == -1)
				break;
			cout << prev[next] << " - ";
			next = prev[next];
		}
		cout << "\n";
	}
}

vector<int> dijkstra(int src) {
	vector<int> dist(V + 1, numeric_limits<int>::max());
	vector<int> prev(V + 1, -1); // -1 이 수정되지 않으면, 그 점이 시작 점이다.
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src)); // pq  첫값이 가중치 인 이유는 첫값을 기준으로 정렬되기 때문.


	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > dist[here]) {
			continue;
		} //무시.  같은 점에 대한 값이 갱신되지만 그 전값도 들어 있으므로

		for (int i = 0; i < adjlist[here].size(); i++) {
			int there = adjlist[here][i].first;
			int nextDist = adjlist[here][i].second + cost;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				prev[there] = here;
				//there는 here로 부터 왔더라.
				pq.push(make_pair(-nextDist, there));

			}
		}

	}
	//print_shortest_path(dist, prev, src);

	return dist;
}

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능

	cin >> V;
	cin >> E;

	adjlist.resize(V + 1);

	int start;
	int end;
	int weight;
	for (int i = 0; i < E; i++) {
		cin >> start;
		cin >> end;
		cin >> weight;
		adjlist[start].push_back(make_pair(end, weight));
	}
	int start_city;
	int end_city;
	cin >> start_city;
	cin >> end_city;

	vector<int> dist = dijkstra(start_city);
	cout << dist[end_city] << "\n";

	return 0;

}
