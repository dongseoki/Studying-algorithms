//https://www.acmicpc.net/problem/1717


#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
	int components;
	vector<int> parent, rank, SIZE;
	UnionFind(int n) : components(n), parent(n), rank(n), SIZE(n, 1) {
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) ++rank[v];
		parent[u] = v;
		SIZE[v] += SIZE[u];
		components--;

		return true;
	}

	int getSize(int u) {
		return SIZE[find(u)];
	}
};
int n;
int m;
int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����
	cin >> n;
	cin >> m;
	int mode;
	int a, b;
	UnionFind uf(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> mode;
		cin >> a;
		cin >> b;
		if (mode == 0) {
			// ��ġ��.
			uf.merge(a, b);
		}
		else if (mode == 1) {
			if (uf.find(a) == uf.find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}