#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N;
int K;
int turn = 1;

class horse {
public :
	int r;
	int c;
	int d;
	horse() {
		r = 0;
		c = 0;
		d = 0;
	}
};

void move_plus_push_pop_stack(int r, int c, int s_r, int s_c, int h_idx, vector<horse>& hs, vector<vector<pair<int, vector<int>>>>& c_map) {
	vector<int> staack;
	while (true) {
		int back_item = c_map[r][c].second.back();
		c_map[r][c].second.pop_back();
		staack.push_back(back_item);
		if (back_item == h_idx) {
			// �츮�� ã���Ŷ�� break;
			break;
		}
	}

	// h_idx ���� ���  ���ؼ�  staack �� ���� ��Ȳ...

	while (!staack.empty()) {
		int back_item = staack.back();
		c_map[s_r][s_c].second.push_back(back_item);
		// map �� �ι�° ������ �� ž�� Ǫ��.

		hs[back_item].r = s_r;
		hs[back_item].c = s_c;
		// Ǫ���� �༮�� r, c ���� ����
		staack.pop_back();
	}

	//hs[h_idx].r = s_r;
	//hs[h_idx].c = s_c;
	// �� �� ��ġ ����

}

void move_plue_push_pop_queue(int r, int c, int s_r, int s_c, int h_idx, vector<horse>& hs, vector<vector<pair<int, vector<int>>>>& c_map) {
	queue<int> queeue;
	while (true) {
		int back_item = c_map[r][c].second.back();
		c_map[r][c].second.pop_back();
		queeue.push(back_item);
		if (back_item == h_idx) {
			// �츮�� ã���Ŷ�� break;
			break;
		}
	}

	// h_idx ���� ���  ���ؼ�  queeue �� ���� ��Ȳ...

	while (!queeue.empty()) {
		int back_item = queeue.front();
		c_map[s_r][s_c].second.push_back(back_item);
		// map �� �ι�° ������ �� ž�� Ǫ��.

		hs[back_item].r = s_r;
		hs[back_item].c = s_c;
		// Ǫ���� �༮�� r, c���� ����.

		queeue.pop();
	}


	//hs[h_idx].r = s_r;
	//hs[h_idx].c = s_c;
	// �� �� ��ġ ����
}

vector<int> d_r = { 0	,0		,0	,-1	,+1 };
vector<int> d_c = { 0	,+1		,-1	,0	,0 };

int reverse_direction(int direction) {
	switch (direction)
	{
	case 1:
		return 2;
		break;
	case 2:
		return 1;
		break;
	case 3:
		return 4;
		break;
	case 4:
		return 3;
		break;

	}
}

pair<int, int> move_horse(int h_idx,int flag, vector<horse>& hs, vector<vector<pair<int, vector<int>>>> & c_map) {

	int r = hs[h_idx].r;
	int c = hs[h_idx].c;
	int direction = hs[h_idx].d;
	int s_r = r +  d_r[direction];
	int s_c = c + d_c[direction];
	// c_map first : color // second : ��ǥ�� statck

	if (1<=s_r && s_r<=N 
		&& 1<=s_c && s_c <=N) {
		// ���� ���϶�,
		int color = c_map[s_r][s_c].first;

		switch (color) {
		case 0:
			move_plus_push_pop_stack(r,c,s_r,s_c,h_idx, hs, c_map);
			return make_pair(s_r, s_c);
			break;
		case 1:
			move_plue_push_pop_queue(r, c, s_r, s_c, h_idx, hs, c_map);
			return make_pair(s_r, s_c);
			break;
		case 2:
			// �Ķ��� ������ ó��.
			// A�� ���� �̵� ������ �ݴ�� �ϰ�
			if (flag == 1) {
				return make_pair(r, c); // ���� �ڱ� ��ġ.
			}
				// �̹� �÷��װ� 1�̶�� �Ķ����� ���ؼ� �ݴ밡 �Ǿ��µ�, �״��� Ž������ �� �Ķ��̸�.. ��� �÷���
			hs[h_idx].d = reverse_direction(hs[h_idx].d);
			 return move_horse(h_idx, 1, hs, c_map);
			// ��ĭ �̵��� �õ�.
			break;
		}
	}
	else {
		// ���� ���� �ƴҶ�,
		// �Ķ��� ó�� ó��.
			// A�� ���� �̵� ������ �ݴ�� �ϰ�
		if (flag == 1) {
			return make_pair(r, c); // ���� �ڱ� ��ġ.
		}
		// �̹� �÷��װ� 1�̶�� �Ķ����� ���ؼ� �ݴ밡 �Ǿ��µ�, �״��� Ž������ �� �Ķ��̸�.. ��� �÷���
		hs[h_idx].d = reverse_direction(hs[h_idx].d);
		return move_horse(h_idx, 1, hs, c_map);
		// ��ĭ �̵��� �õ�.
	}
}

int main(void) {

	cin >> N;
	cin >> K;

	vector<vector<pair<int, vector<int>>>> c_map(N + 1, vector<pair<int, vector<int>>>(N + 1, make_pair(0,vector<int>()) )); // color map
		// index start from 1.

	vector<horse> hs(K + 1, horse()); // 
	
	// index start from 1.



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// N * N ũ���� ����.
			cin >>c_map[i][j].first;
		}
	}

	// and...

	for (int h_idx = 1; h_idx <= K; h_idx++) {
		// K���� ��.
		cin >> hs[h_idx].r;
		cin >> hs[h_idx].c;
		cin >> hs[h_idx].d;

		int r = hs[h_idx].r;
		int c = hs[h_idx].c;

		c_map[r][c].second.push_back(h_idx);
	}

	for (; turn <= 1000; turn++) {
		// 1000���� ��

		for (int h_idx = 1; h_idx <= K; h_idx++) {
			// K���� ��.
			pair<int, int> now = move_horse(h_idx, 0, hs, c_map);

			int c_size = c_map[now.first][now.second].second.size();
			if (c_size >= 4) {
				cout << turn;
				return 0;
			}
			// �� ���� �̵������� ���� 4�� ������ ����.
		}
	}
	cout << "-1";
	return 0;

}