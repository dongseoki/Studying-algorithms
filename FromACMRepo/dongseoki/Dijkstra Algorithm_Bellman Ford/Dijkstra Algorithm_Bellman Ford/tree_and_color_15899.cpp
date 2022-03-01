#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int M;
int C;
int anss; // answers �� ����.

vector<vector<pair<int, int>>> memo(200000);
vector<vector<int>> al(200000);//adjacent list ��������Ʈ �ظ�.
vector<int> tc; // �츰 �ε��� 0�� ���Ŵ�.tree color �� ����.
vector<bool> visited(200000, false);

int find(int v,int c) {
	for (int i = 0; i < memo[v].size(); i++) {
		if (memo[v][i].first == c)
			return memo[v][i].second;
	}

	return -1;
}

int f(int v, int c) {

	if (al[v].size() == 1 && visited[v] == true) {
		if (tc[v] <= c) {
			return 1;
		}
		else {
			return 0;
		}
	}// ���� ���� �׸� ã��.

	int result = find(v, c);
	if (result != -1) {
		return result;
	}// �̹� �ִ� ���̳� ��

	result = 0;// ���ϱ�. ����.

	for (int i = 0; i < al[v].size(); i++) {
		if (visited[al[v][i]] == false) {
			visited[al[v][i]] = true;
			visited[v] = true;
			if (tc[v] <= c) {
				result += (1 + f(al[v][i], c));
			}
			else {
				result += f(al[v][i], c);
			}
			visited[v] = false;
			visited[al[v][i]] = false;
		}

	}
	
	// ���� ���� ������ ������ ���̴� �߰�����.
	memo[v].push_back(make_pair(c, result));

	return result;	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> M;
	cin >> C;
	tc.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> tc[i];
	}
	int a;
	int b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		cin >> b;
		al[a - 1].push_back(b - 1);
		al[b - 1].push_back(a - 1);
	}

	int v;
	int c;
	int sum;
	for (int i = 0; i < M; i++) {
		cin >> v;
		cin >> c;
		sum = f(v, c);
		cout << sum << "\n";
		anss +=sum;
		anss %= 1000000007;
	}
	cout << anss;

}