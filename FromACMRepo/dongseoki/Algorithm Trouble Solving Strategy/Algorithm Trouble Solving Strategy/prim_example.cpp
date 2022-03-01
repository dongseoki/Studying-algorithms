//code by RiKang, weeklyps.com
//#include <bits/stdc++.h>
#include <vector>
#define PII pair<int,int>

using namespace std;

const int N = 1005, INF = 2140000000;

vector<PII> ad[N];  // ad[i] : i ��尡 ������� ������, first = ������, second = ���
int dist[N];        // dist[i] : ���õ� ����� i ��尡 ����Ǿ� �ִ� ������ ��� �� �ּҺ��
bool selected[N];   // selected[i] : i �� ������ ���õ� ����ΰ�?

long long prim(int pn) {
	long long ret = 0;
	for (int i = 1; i <= pn; i++) { // �ʱ�ȭ
		dist[i] = INF;
		selected[pn] = false;
	}
	dist[1] = 0;              // 1�� ������ ����
	for (int i = 1; i <= pn; i++) {
		int now = -1, min_dist = INF;
		for (int j = 1; j <= pn; j++) {
			if (!selected[j] && min_dist > dist[j]) {
				min_dist = dist[j];
				now = j;
			}
		}
		if (now < 0) return (long long)INF; // ���� �׷����� �ƴ�
		ret += min_dist;
		selected[now] = true;
		for (auto edge : ad[now])
			dist[edge.first] = min(dist[edge.first], edge.second);
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int v1, v2, c;
		scanf("%d %d %d", &v1, &v2, &c);
		ad[v1].push_back(PII(v2, c));
		ad[v2].push_back(PII(v1, c));
	}
	printf("%lld", prim(n));
	return 0;
}


//��ó: https://www.weeklyps.com/entry/����-�˰���-Prims-algorithm#d5 [weekly ps]