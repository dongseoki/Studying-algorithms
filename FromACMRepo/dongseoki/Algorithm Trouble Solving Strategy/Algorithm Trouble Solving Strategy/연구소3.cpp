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
vector<vector<int>> r_map(52, vector<int>(52, 1)); // research map. �����Ҹ�
	// ���� 
	//111111111
	//10------1
	//111111111
	// �̷� ����.

int cnt = 0;
void virus_pick(int picked_num, int pre_value, vector<int>& v_pos, vector<bool>& visited) {
	if (picked_num >= M) {
		// degenerate case;
		// �� �����. ����
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
			// Ž���� ����. 
			// �������� 1. Ž���Ϸ��� ���� �ʻ����� 0�̿��� �Ѵ�.
			//2-1. �湮�� ���� �ʾҾ���Ѵ�.
			//�Ǵ�
			//2-2. �湮�� �Ǿ��ٸ�, ���� Ž���� �ð��� �װ��� ���� ������ �۾ƾ��Ѵ�.
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
	vector<vector<int>> t_map(52, vector<int>(52, -1)); // time map. �Ź� �����ؼ� ���.
	F(x, 0, seq.size()) {
		if (seq[x] == 1) {
			// ���̷��� ��� ��.
			BFS(x, t_map, v_pos, seq);// �۶߸���.
		}
	}

	int allvirustime = is_it_spreaded_all_plus_virustime(t_map, v_pos, seq);

	return allvirustime;
}

//�ݺ�
//���̷����� ����.
// �۶߸���.
// ��� �����ִ��� Ȯ��
// �ð��� ����. �� �� �ּڰ��� ����.

// ���� �ݺ��� ������ ã�� ���Ѵٸ� -1�� ����Ѵ�.
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

	// 1. �Է�.
	Input(v_pos);

	//1, �ݺ�.
	// ���̷����� ����.
	vector<int> seq(M, 1);
	F(x, 0, (v_pos.size() - M)) {
		seq.push_back(0);
	}

	//virus_pick(0, v_pos, seq);
	sort(seq.begin(), seq.end());
	do {
		cnt++;
		// ���̷����� �ٰ����!
		// ���̷��� �ϳ��� ��� �۶߸���.
		int allvirustime =  SpreadVirus(v_pos, seq);

		if (allvirustime != -1) {
			// ���� �ִٸ� �ϳ���.
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