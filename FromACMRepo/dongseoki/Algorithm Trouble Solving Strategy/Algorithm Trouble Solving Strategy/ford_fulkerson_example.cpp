//https://blog.naver.com/infoefficien/220101847802

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int INF = (1 << 30);
const int MAX_V = 100;
int V;

//capacity[u][v]=u���� v�� ���� �� �ִ� �뷮
//flow[u][v]=u���� v�� �귯���� ���� (�ݴ� ������ ��� ����)
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

//flow[][]�� ����ϰ� �� ������ ��ȯ�Ѵ�.
int networkflow(int source, int sink) {
	//flow�� 0���� �ʱ�ȭ �Ѵ�.
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	while (true) {
		//�ʺ� �켱 Ž������ ���� ��θ� ã�´�.
		vector<int> parent(MAX_V, -1);
		queue<int>q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == -1) {
			int here = q.front();
			q.pop();
			for (int there = 0; there < V; ++there)
				if (capacity[here][there] - flow[here][there] > 0 &&
					parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}
		//���� ��ΰ� ������ �����Ѵ�.
		if (parent[sink] == -1) break;
		//���� ��θ� ���� ������ �󸶳� ������ �����Ѵ�.
		int amount = INF;
		for (int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);

		//���� ��θ� ���� ������ ������.
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}

		totalFlow += amount;
	}

	return totalFlow;
}
int main(void) {
	int E; // edge;
	int source;
	int sink;
	cin >> V;
	cin >> E;
	cin >> source;
	cin >> sink;
	for (int i = 0; i < E; i++) {
		int start;
		int end;
		int cap;
		cin >> start;
		cin >> end;
		cin >> cap;
		capacity[start][end] = cap;
	}

	cout << networkflow(source, sink);
}
//[��ó] C++ - ���� ǮĿ�� ���(������ ī�� �˰���) �� �ּ� �� �ִ����� | �ۼ��� Gauss
//4
//5
//1 3
//1 0 2
//1 2 5
//0 2 1
//0 3 4
//2 3 3

