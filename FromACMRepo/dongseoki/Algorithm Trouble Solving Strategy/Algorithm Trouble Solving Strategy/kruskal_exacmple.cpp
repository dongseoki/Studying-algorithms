//code by RiKang, weeklyps.com
#include<stdio.h>
#include<algorithm>
#include<vector>
#include <iostream>

using namespace std;

const int N = 100005;
// 유니온 파인드 시작
struct union_find_tree {
	vector<int> parent;
	vector<int> height;
	vector<int> group_size;

	void init(int uf_n) {
		parent.clear(), height.clear();
		group_size.clear();
		for (int i = 0; i < uf_n; i++) {
			parent.push_back(i);
			height.push_back(0);
			group_size.push_back(1);
		}
	}

	int get_root(int now) {
		if (parent[now] == now) return now;
		return parent[now] = get_root(parent[now]);
	}

	bool same_set(int v1, int v2) {
		return get_root(v1) == get_root(v2);
	}

	void merge(int v1, int v2) {
		v1 = get_root(v1), v2 = get_root(v2);
		if (v1 == v2) return;
		if (height[v1] < height[v2]) swap(v1, v2);
		parent[v2] = v1;
		group_size[v1] += group_size[v2];
		if (height[v1] == height[v2])
			height[v1]++;
	}
}uf;
// 유니온 파인드 끝

struct edge {
	int v1, v2, cost;
	edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost)
	{}
	bool operator < (const edge& e1) const { return cost < e1.cost; }
};
vector<edge> e;

int kruskal(int kn) {
	uf.init(kn + 1);
	sort(e.begin(), e.end());
	int ret = 0;     // 간선 가중치의 합의 최솟값
	for (auto now : e) {
		if (!uf.same_set(now.v1, now.v2)) { // 두 정점이 끊어져 있는가?
			ret += now.cost;       // 가중치를 ret에 더함
			uf.merge(now.v1, now.v2); // 두 정점 연결
		}
	}
	return ret;
}

int main() {
	/*
	간선 입력 부분
	*/
	int V,E;
	cin >> V;
	cin >> E;
	for (int i = 0; i < E; i++) {
		int start;
		int end;
		int cost;
		cin >> start;
		cin >> end;
		cin >> cost;
		e.push_back(edge(start, end, cost));
	}
	int ans = kruskal(N);
	cout << ans;
	return 0;
}

//예시 입력

//7 9
//1 3 1
//1 2 5
//3 4 4
//4 2 1
//4 5 5
//4 7 3
//6 7 2
//2 7 3
//2 6 3


//출처: https://www.weeklyps.com/entry/크루스칼-알고리즘-Kruskals-algorithm [weekly ps]