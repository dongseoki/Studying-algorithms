
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//vector<vector<int> > arr(6, vector<int>(5, 0));
vector<vector<int> > trvec(500000);            // index 0 사용.
vector<bool > visited(500000, false);

int N;
int result;

void dfs(int state, int sum) {
	//visited[state] = true;

	if (trvec[state].size() == 1 && visited[trvec[state][0]] ==true) {
		result += sum;
		return;
	}
	for (int i=0; i < trvec[state].size();i++) {
		if (visited[trvec[state][i]] == false) {
			visited[trvec[state][i]] = true;
			visited[state] = true;
			dfs(trvec[state][i], sum + 1);
			visited[state] = false;
			visited[trvec[state][i]] = false;
			//visited[i] = false; 필요없다.
		}
		
	}

}

bool leafcheck(int state) {
	if (trvec[state].size() == 1 && visited[trvec[state][0]] == true)
		return true;
	else
		return false;
}

void bfs(int state) {
	vector<int> memo(N, 0);
	int sum = 0;
	/*1. queue 에 시작점을 넣고, 그 점을 true로
		2. while 문에 진입 queue 가 빌때 까지 시도
		3. queue 에서 하나 뺴고
		// 여기서 그 점이 리프면은 continue 해서 와일 초기로.
		4. 뺀 그점과 인접한 점을 모두조사 for문진입
		5. 그 해당 점이 false다!그렇다면 이제
		큐에 넣고 visited[w] 를 true로!*/
	queue<int> q;
	vector<int> parent(N, 0);
	q.push(state);
	visited[state] = true;
	//1 . 

	int v;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		parent[v] + 1;
		if (leafcheck) {
			sum += 1;
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int a;
	int b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		cin >> b;
		trvec[a - 1].push_back(b - 1);
		trvec[b - 1].push_back(a - 1);
	}

	dfs(0, 0);
	if (result % 2 == 0)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}