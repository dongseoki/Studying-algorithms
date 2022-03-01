#include <iostream>
#include <vector>
#include <limits>
#include <utility>//pair ���� ���
#include <queue>

using namespace std;

int V;
int E;
vector<vector<pair<int, int>>> adjlist;



vector<int> dijkstra(int src) {
	vector<int> dist(V + 1, numeric_limits<int>::max());
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src)); // pq  ù���� ����ġ �� ������ ù���� �������� ���ĵǱ� ����.


	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > dist[here]) {
			continue;
		} //����.  ���� ���� ���� ���� ���ŵ����� �� ������ ��� �����Ƿ�

		for (int i = 0; i < adjlist[here].size(); i++) {
			int there = adjlist[here][i].first;
			int nextDist = adjlist[here][i].second + cost;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));

			}
		}

	}

	return dist;
}

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����

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
