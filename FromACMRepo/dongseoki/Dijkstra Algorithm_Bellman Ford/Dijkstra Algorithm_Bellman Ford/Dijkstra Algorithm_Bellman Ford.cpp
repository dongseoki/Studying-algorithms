#include <iostream>
#include <iostream>
#include <vector>
#include <utility>//pair 포함 헤더
#include <limits>
#include <queue>

//https://jaimemin.tistory.com/555


using namespace std;
int V;
int E;
const int   MAX_V =  20000+1;
vector<pair<int, int>> adj[MAX_V];
vector<int> dijkstra(int src) {
	vector<int> dist(V, numeric_limits<int>::max());
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	//pq.push(make_pair(src, 0));
	pq.push(make_pair(0,src));
	while (!pq.empty()) {
		//int here = pq.top().first;
		//int cost = pq.top().second;

		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (dist[here] < cost)
			continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main(void)
{
	int src;
	scanf_s("%d %d", &V, &E);
	scanf_s("%d", &src);

	V++;

	int start;
	int end;
	int weight;
	//adj.push_back;
	for (int i = 0; i < E; i++) {
		scanf_s("%d %d %d", &start, &end,&weight);
		//adj[start].push_back(make_pair(0, 0));
		adj[start].push_back(make_pair(end, weight));
	}
	vector<int> result= dijkstra(src);
	//dijkstra(src);
	for (int i = 1; i < V; i++) {
		if(result[i] ==numeric_limits<int>::max())
			printf("INF\n");
		else
			printf("%d\n", result[i]);
	}
	//pair 주의 사항  보통은 std::pair에 있다. 따라서 using namespace std 를 해야 걍 pair로 가능.
}

void showPair(std::pair<int, double> input)
{
	std::cout << "pair 첫번째 인자 " << input.first << std::endl;//.first... pair의 첫번째 인자에 접근
	std::cout << "pair 첫번째 인자 " << input.second << std::endl << std::endl;//.second... pair의 첫번째 인자에 접근


}