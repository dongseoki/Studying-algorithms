#include <iostream>
#include <iostream>
#include <vector>
#include <utility>//pair ���� ���
#include <limits>
#include <queue>

//https://jaimemin.tistory.com/555


using namespace std;
int V;
int E;
const int   MAX_V = 20000 + 1;
vector<pair<int, int>> adj[MAX_V];

vector<int> bellmanFord(int src) {
	vector<int> upper(V, numeric_limits<int>::max());
	upper[src] = 0;
	bool updated ;

	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for(int here=0;here<V;++here)
			for (int i = 0; i< adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		if (!updated)
			break;
	}

	if (updated)
		upper.clear();
	return upper;
}

int main(void)
{
	int src;
	scanf_s("%d %d", &V, &E);
	//scanf_s("%d", &src);

	V++;

	int start;
	int end;
	int weight;
	//adj.push_back;
	for (int i = 0; i < E; i++) {
		scanf_s("%d %d %d", &start, &end, &weight);
		//adj[start].push_back(make_pair(0, 0));
		adj[start].push_back(make_pair(end, weight));
	}
	vector<int> result = bellmanFord(1);
	//dijkstra(src);
	for (int i = 2; i < V; i++) {
		if (!result.empty()) {
			if (result[i] < numeric_limits<int>::max())
				printf("%d\n", result[i]);
			else
				printf("%d\n", -1);
		}
		else {
			printf("%d\n", -1);
			//printf("hi");
			break;
		}
			
		
	}
	//pair ���� ����  ������ std::pair�� �ִ�. ���� using namespace std �� �ؾ� �� pair�� ����.
}

void showPair(std::pair<int, double> input)
{
	std::cout << "pair ù��° ���� " << input.first << std::endl;//.first... pair�� ù��° ���ڿ� ����
	std::cout << "pair ù��° ���� " << input.second << std::endl << std::endl;//.second... pair�� ù��° ���ڿ� ����


}