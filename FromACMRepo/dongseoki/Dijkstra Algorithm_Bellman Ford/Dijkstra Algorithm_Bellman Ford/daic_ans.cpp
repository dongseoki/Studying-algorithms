#include <iostream>

#include <vector>

#include <queue>

using namespace std;



const int MAX = 20000 + 1;

const int INF = 987654321;



int V, E, K;

vector<pair<int, int>> graph[MAX];



vector<int> dijkstra(int start, int vertex)

{

	vector<int> distance(vertex, INF); //start�� �������� �Ÿ�

	distance[start] = 0; //�ڱ� �ڽ����� ���� ��� 0



	priority_queue<pair<int, int>> pq; //Cost, Vertex

	pq.push(make_pair(0, start)); //�ʱ� ���� ������



	while (!pq.empty())

	{

		int cost = -pq.top().first; //�Ÿ��� ��ȣ�� �ٲپ� �Ÿ��� ���� �������� �������� �Ͽ����Ƿ� ��ȣ�� �ٲ��ش�

		int curVertex = pq.top().second;

		pq.pop();



		//�ּҰŸ��� ���ϹǷ�

		if (distance[curVertex] < cost)

			continue;



		//neighbor �� Ȯ��

		for (int i = 0; i < graph[curVertex].size(); i++)

		{

			int neighbor = graph[curVertex][i].first;

			int neighborDistance = cost + graph[curVertex][i].second;



			//�ּ� ��� �߽߰� ������Ʈ

			if (distance[neighbor] > neighborDistance)

			{

				distance[neighbor] = neighborDistance;

				//�Ÿ��� ��ȣ�� �ٲپ� �Ÿ��� ���� �������� �����������ϱ� ����

				pq.push(make_pair(-neighborDistance, neighbor));

			}

		}

	}

	return distance;

}



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cin >> V >> E >> K;



	V++; //������ȣ 1���� ����



	for (int i = 0; i < E; i++)

	{

		int source, destination, cost;

		cin >> source >> destination >> cost;



		graph[source].push_back(make_pair(destination, cost));

	}



	vector<int> result = dijkstra(K, V);



	for (int i = 1; i < V; i++)

	{

		if (result[i] == INF)

			cout << "INF\n";

		else

			cout << result[i] << "\n";

	}

	return 0;

}