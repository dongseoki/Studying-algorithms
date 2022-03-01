#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#define F(p,q,r) for(int p=q;p<r;p++)
using namespace std;
void print_map(vector<vector<int>> p_map);
int N;
int M;
vector<vector<int>> r_map(52, vector<int>(52, 1)); // research map. 연구소맵
	// 맵은 
	//111111111
	//10------1
	//111111111
	// 이런 느낌.

int cnt = 0;
void virus_pick(int picked_num, int pre_value, vector<int>& v_pos, vector<bool>& visited) {
	if (picked_num >= M) {
		// degenerate case;
		// 다 골랐다. 이제
		cnt++;
		F(x, 0, v_pos.size()) {
			cout << visited[x] << " ";
		}
		cout << "\n";
		return;
	}
	F(x, picked_num, v_pos.size()) {
		if (visited[x] == false && x > pre_value) {
			visited[x] = true;
			virus_pick(picked_num + 1,x, v_pos, visited);
			visited[x] = false;
		}
	}
}

void Input(vector<pair<int, int>>& v_pos) {
	F(x, 1, (N + 1)) {
		F(y, 1, (N + 1)) {
			cin >> r_map[x][y];
			if (r_map[x][y] == 2) {
				v_pos.push_back(make_pair(x, y));
			}
		}
	}
}
vector<int> d_row = { 0,0,-1,+1 };
vector<int> d_column = { +1,-1,0,0 };

void BFS(int v_idx ,vector<vector<int>> & t_map,vector<pair<int, int>> & v_pos, vector<int>& seq) {
	queue<pair<int, int>> q;
	pair<int, int> virus_point = v_pos[v_idx];
	q.push(make_pair(virus_point.first, virus_point.second));
	t_map[virus_point.first][virus_point.second] = 0;
	while (!q.empty()) {
		pair<int, int> here = q.front();
		q.pop();
		F(direction, 0, 4) {
			int s_row = here.first + d_row[direction];
			int s_column = here.second + d_column[direction];
			int s_time = t_map[here.first][here.second] + 1;
			// 탐색의 조건. 
			// 절대조건 1. 탐색하려는 곳이 맵상으로 0이여야 한다.
			//2-1. 방문이 되지 않았어야한다.
			//또는
			//2-2. 방문이 되었다면, 내가 탐색한 시간이 그곳에 쓰인 값보다 작아야한다.
			if (r_map[s_row][s_column] == 0 || r_map[s_row][s_column] == 2) {
				if (t_map[s_row][s_column] == -1) {
					t_map[s_row][s_column] = s_time;
					q.push(make_pair(s_row, s_column));
				}
				else if (s_time < t_map[s_row][s_column]) {
					t_map[s_row][s_column] = s_time;
					q.push(make_pair(s_row, s_column));
				}
			}
			

		}
	}

}
int is_it_spreaded_all_plus_virustime(vector<vector<int>>& t_map, vector<pair<int, int>>& v_pos, vector<int>& seq) {
	int allvirustime = 0;
	F(x, 1, (N + 1)) {
		F(y, 1, (N + 1)) {
			if (r_map[x][y] == 0) {
				if (t_map[x][y] == -1)
					return -1;
				// 
				else {
					allvirustime = max(allvirustime, t_map[x][y]);
				}
			}
		}
	}

	return allvirustime;
}


int SpreadVirus(vector<pair<int, int>>& v_pos, vector<int> & seq) {
	vector<vector<int>> t_map(52, vector<int>(52, -1)); // time map. 매번 생성해서 사용.
	F(x, 0, seq.size()) {
		if (seq[x] == 1) {
			// 바이러스 라는 뜻.
			BFS(x, t_map, v_pos, seq);// 퍼뜨리자.
		}
	}

	int allvirustime = is_it_spreaded_all_plus_virustime(t_map, v_pos, seq);

	return allvirustime;
}

//반복
//바이러스를 고른다.
// 퍼뜨린다.
// 모두 퍼져있는지 확인
// 시간을 저장. 이 때 최솟값을 갱신.

// 위의 반복이 끝나도 찾지 못한다면 -1을 출력한다.
void print_map(vector<vector<int>> p_map) {
	F(x, 0, (N + 2)) {
		F(y, 0, (N + 2)) {
			printf("%3d ", p_map[x][y]);
		}
		cout << "\n";
	}
}

int solution() {
	int answer = 999999;
	vector<pair<int, int>> v_pos;

	bool a_flag = false;

	// 1. 입력.
	Input(v_pos);

	//1, 반복.
	// 바이러스를 고른다.
	vector<int> seq(M, 1);
	F(x, 0, (v_pos.size() - M)) {
		seq.push_back(0);
	}

	//virus_pick(0, v_pos, seq);
	sort(seq.begin(), seq.end());
	do {
		cnt++;
		// 바이러스를 다골랐다!
		// 바이러스 하나씩 골라서 퍼뜨리자.
		int allvirustime =  SpreadVirus(v_pos, seq);

		if (allvirustime != -1) {
			// 답이 있다면 하나라도.
			a_flag = true;
			answer = min(answer, allvirustime);
		}


	} while (next_permutation(seq.begin(), seq.end()));

	//cout << cnt<<" for test\n";

	if (a_flag == false)
		return -1;
	else
		return answer;
}
int main(void) {
	//M = 3;
	//vector<int> v_pos{ 1,2,3,4,5 };
	//vector<bool> visited(5, false);
	//virus_pick(0, -1, v_pos, visited);
	cin >> N;
	cin >> M;
	cout << solution();
}