#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

long long int N;
long long int M;
long answer[200001];
vector<long long int> graph[200001]; // 사람들 관계 그래프
set<long long int> adj; // 인접한 사람들 찾는 set
// set  인접한 사람들 중에 적어도 한명은 믿고 있는데, 자신은 믿고 있지 않는 사람들의 번호의 집합.


void input();
void solve();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();
	for (long long int i = 1; i <= N; i++) {
		cout << answer[i] << ' ';
	}
	//cout << '\n';
}

void input() {
	memset(answer, -1, sizeof(answer) / sizeof(long long int));
	cin >> N;
	long long int tmp;
	for (long long int i = 1; i <= N; i++) {
		while (true) {
			cin >> tmp;
			if (tmp != 0) 
				graph[i].push_back(tmp);
			
			else 
				break;
		}
	}

	cin >> M;

	//for (long long int i = 1; i <= M; i++) {
	//	cin >> tmp;
	//	answer[tmp] = 0;
	//	for (long long int i = 0; i < graph[tmp].size(); i++) {
	//		if (answer[graph[tmp][i]] == -1) adj.insert(graph[tmp][i]); // 유포자와 연결된 주변인이 유포자가 아니라면,  인접 셋에 추가.
	//	}
	//}

	vector<int> YupoList;
	for (long long int i = 0; i < M; i++) {
		cin >> tmp;
		YupoList.push_back(tmp);
		answer[tmp] = 0;
	}



	for (long long int i = 0; i < M; i++) {
		int yupoNum = YupoList[i];
		for (long long int j = 0; j < graph[yupoNum].size(); j++) {
			if (answer[graph[yupoNum][j]] == -1)
				adj.insert(graph[yupoNum][j]); // 유포자와 연결된 주변인이 유포자가 아니라면,  인접 셋에 추가.
		}
	}
}

void solve() {

	long long int flag = 1; // 변화가 있었는지 확인하는 플래그, 변화가 있으면 1, 없으면 0
	long long int time = 1;
	while (flag == 1) {
		flag = 0;
		vector<long long int> insert_list; // adj set에 추가될 리스트
		vector<long long int> erase_list; // adj set에서 제거할 리스트
		for (set<long long int>::iterator iter = adj.begin(); iter != adj.end(); iter++) { // 인접한 곳이 루머를 믿는 모든 사람들에 대하여(자기가 루머를 안 믿음)
			long long int me = *iter; // me == 본인
			long long int rumor_size = graph[me].size(); // 주변인 수
			long long int cnt = 0; // 주변인 중 믿는 사람 수
			for (long long int i = 0; i < rumor_size; i++) {
				if (answer[graph[me][i]] != -1) 
					cnt++; // 인접인이 루머를 믿는 경우, cnt값을 증가
			}

			if (cnt * 2 >= rumor_size) { // 주변인의 절반 이상이 루머를 믿으면
				erase_list.push_back(me); // 자신을 인접인 집합에서 제거__예정
				for (long long int i = 0; i < graph[me].size(); i++) { // 자신의 주변인들 중
					if (answer[graph[me][i]] == -1) 
						insert_list.push_back(graph[me][i]); // 루머를 믿지 않는 사람을 인접인 집합에 삽입 예정
				}
				flag = 1; // 변화가 있었으므로, 플래그를 1로 변경해준다.
			}
		}


		for (long long int i = 0; i < erase_list.size(); i++) { // 이번 time에 믿은 사람들
			if (answer[erase_list[i]] == -1) 
				answer[erase_list[i]] = time; // 자신이 믿은 시각에 현재 시각을 업데이트 하고,
			adj.erase(erase_list[i]);
		}


		for (long long int i = 0; i < insert_list.size(); i++) { // 이번 time에 믿은 사람의 주변인 들(중 안 믿는 사람)
			if (answer[insert_list[i]] == -1)
				adj.insert(insert_list[i]);
		}
		time++;
	}
}