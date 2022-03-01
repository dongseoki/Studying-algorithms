
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//vector<vector<int> > arr(6, vector<int>(5, 0));
vector<vector<int> > trvec(500000);            // index 0 ���.
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
			//visited[i] = false; �ʿ����.
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
	/*1. queue �� �������� �ְ�, �� ���� true��
		2. while ���� ���� queue �� ���� ���� �õ�
		3. queue ���� �ϳ� ����
		// ���⼭ �� ���� �������� continue �ؼ� ���� �ʱ��.
		4. �� ������ ������ ���� ������� for������
		5. �� �ش� ���� false��!�׷��ٸ� ����
		ť�� �ְ� visited[w] �� true��!*/
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