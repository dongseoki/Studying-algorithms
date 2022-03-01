#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int M;
int C;
int anss; // answers 의 약자.

vector<vector<pair<int, int>>> memo(200000);
vector<vector<int>> al(200000);//adjacent list 인접리스트 준말.
vector<int> tc; // 우린 인덱스 0도 쓸거다.tree color 의 약자.
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
	}// 리프 노드다 그만 찾자.

	int result = find(v, c);
	if (result != -1) {
		return result;
	}// 이미 있는 값이네 ㅋ

	result = 0;// 구하기. 시작.

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
	
	// 여기 까지 왔으면 없었던 값이니 추가하자.
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