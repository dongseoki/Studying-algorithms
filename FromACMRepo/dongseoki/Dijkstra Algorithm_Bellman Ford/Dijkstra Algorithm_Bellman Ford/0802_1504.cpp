#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

int V;
int E;
vector<vector<pair<int, int>>> adjlist;
//vector<vector<pair<int, int>>> adjlist2;

vector<int> dij(int src) {
	vector<int> dist(V + 1, numeric_limits<int>::max());
	priority_queue < pair<int, int>> pq;
	
	dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here])
			continue;
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
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능


	cin >> V;
	cin >> E;
	adjlist.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int start;
		int end;
		int weight;
		cin >> start;
		cin >> end;
		cin >> weight;

		adjlist[start].push_back(make_pair(end, weight));
		adjlist[end].push_back(make_pair(start, weight));
	}
	int p1, p2;
	cin >> p1;
	cin >> p2;
	


	int min_distance = numeric_limits<int>::max();
	int sum = 0;
	
	// 0번 째 시도. 2---X--->3 이냐?
	vector<int> dist = dij(p1);

	//cout << "\n";
	//for (int i = 0; i < dist.size(); i++) {
	//	cout << dist[i] << " ";
	//}
	//cout << "\n";

	if (dist[p2] == numeric_limits<int>::max()) {
		cout << "-1\n";
		return 0;
	}
	int dist_p1_p2 = dist[p2];
	//cout << "distp1p2 : " << dist_p1_p2 << "\n";

	dist = dij(1);
	// 첫 시도. 1 -->2(p1)--->3---> N
	if (dist[p1] != numeric_limits<int>::max()) {
		//cout << "2 : " << dist[p1] << "\n";
		sum = dist[p1] + dist_p1_p2;
		dist = dij(p2);
		if (dist[V] != numeric_limits<int>::max()) {
			//cout << "3 : " << dist[V] << "\n";
			min_distance = min(min_distance, sum + dist[V]);
		}
	}

	dist = dij(1);
	// 두번째 시도. 1 -->3(p2)--->2---> N
	if (dist[p2] != numeric_limits<int>::max()) {
		sum = dist[p2] + dist_p1_p2;
		dist = dij(p1);
		if (dist[V] != numeric_limits<int>::max()) {
			min_distance = min(min_distance, sum + dist[V]);
		}
	}


	// 계산한 값 출력하기.
	if (min_distance == numeric_limits<int>::max())
		cout << "-1\n";
	else
		cout << min_distance << "\n";


	return 0;
}