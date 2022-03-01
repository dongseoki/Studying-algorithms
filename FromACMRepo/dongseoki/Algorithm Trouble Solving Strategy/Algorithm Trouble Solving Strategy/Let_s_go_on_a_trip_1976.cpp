//https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjmat; // adjacent matrix.

struct UnionFind {
	vector<int> parent, rank, SIZE;
	// constructor . initialization.
	UnionFind(int n) :parent(n), rank(n, 1), SIZE(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}

	bool merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v)
			return false; // Union is failed. 2 elements are in the same set.
		// ����. u �� v���� ���� Ʈ����. �׷��� u�� v�� ���� ���� ����.
		if (rank[u] > rank[v])
			swap(u, v);
		if (rank[u] == rank[v])
			++rank[v]; 
		// ������ u�� ��Ʈ�� v�� �� ���̶� u�� ��ũ�� �ٲ� �ʿ䰡 ����
		//�Ƹ� ���̻� ������ ���� ���� ����.

		parent[u] = v;
		SIZE[v] += SIZE[u];
	}

	int getSize(int u) {
		return SIZE[find(u)];
	}
};

int main(void) {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int N;// N is number of citys.
	int M; // M is number of citys which is included with trip plan.

	cin >> N;
	adjmat.assign(N, vector<int>(N, 0));
	UnionFind uf(N);

	cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &adjmat[i][j]);
			if (adjmat[i][j] == 1) {
				uf.merge(i, j);
			}
		}
	}
	if (M == 0) {
		cout << "YES\n";
		return 0;
	}

	// else. M >=1;
	int city;
	scanf("%d", &city);
	int setnum = uf.find(city-1);
	for (int i = 1; i < M; i++) {
		scanf("%d", &city);
		if (setnum != uf.find(city-1)) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
}