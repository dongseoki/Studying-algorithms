#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#define F(p,q,r) for(int p=q;p<r;p++)
#define SHARK 0
#define EMPTY -1
int ans = 0;

using namespace std;
class Fish {
public:
	int row_pos;
	int column_pos;
	int dir;
	bool isAlive;
	Fish(int row_pos, int column_pos, int dir, bool isAlive) {
		this->row_pos = row_pos;
		this->column_pos = column_pos;
		this->dir = dir;
		this->isAlive = isAlive;
	}
};

void Input(vector<Fish> & fish_vec, vector<vector<int>> & fish_map) {
	F(R, 0, 4) {
		F(C, 0, 4) {
			int fishNum = -1;
			int fishDir = -1;
			cin >> fishNum;
			cin >> fishDir;
			fish_vec[fishNum] = Fish(R, C, fishDir, true);
			fish_map[R][C] = fishNum;
		}
	}
}
int init_shark(vector<Fish>& fish_vec, vector<vector<int>>& fish_map) {
	int dead_fishNum = fish_map[0][0];
	fish_map[0][0] = 0;
	// map ���� - ���� �����.

	fish_vec[dead_fishNum].isAlive = false;
	fish_vec[SHARK] = Fish(0, 0, fish_vec[dead_fishNum].dir, true);
	// vec ����. ��� 0,0 ���� ����� ����, �������.   ���� ����� ����!

	return dead_fishNum;
}
//			       ��, ��, ��, ��, ��, ��, ��, ��
int dir_R[] = { -8, -1, -1, 0, +1, +1, +1, 0, -1 };
int dir_C[] = { -8, 0, -1, -1, -1, 0, +1, +1, +1 };
void changeDir(int& dir) {
	// �̰��� ��¥�� �ٲ..!
	dir++;
	dir = dir % 8;
	if (dir == 0) {
		dir = 8;
	}
}
void changeTwoFishPos(int nowFishNum, int targetFishNum, vector<Fish>& fish_vec, vector<vector<int>>& fish_map) {
	// vec �� �ִ� ����� ���� ���� ����.

	Fish tempFishData = fish_vec[targetFishNum];
	fish_vec[targetFishNum].row_pos = fish_vec[nowFishNum].row_pos;
	fish_vec[targetFishNum].column_pos = fish_vec[nowFishNum].column_pos;
	
	fish_vec[nowFishNum].row_pos = tempFishData.row_pos;
	fish_vec[nowFishNum].column_pos = tempFishData.column_pos;

	// fish_map �� ���� ������ ��ġ�� ����.

	fish_map[fish_vec[nowFishNum].row_pos][fish_vec[nowFishNum].column_pos] = nowFishNum;
	fish_map[fish_vec[targetFishNum].row_pos][fish_vec[targetFishNum].column_pos] = targetFishNum;
}

void try_move_fish(int fishNum, vector<Fish>& fish_vec, vector<vector<int>>& fish_map) {
	F(dir_count, 0, 8) {
		int S_row_pos = fish_vec[fishNum].row_pos + dir_R[fish_vec[fishNum].dir];
		int S_column_pos = fish_vec[fishNum].column_pos + dir_C[fish_vec[fishNum].dir];
		if ((S_row_pos < 0 || S_row_pos>3) || (S_column_pos < 0 || S_column_pos>3)) {
			// ��谪 ���� ���� ���ٸ�.
			changeDir(fish_vec[fishNum].dir);
			continue;
		}
		else if (fish_map[S_row_pos][S_column_pos] == SHARK) {
			// Ž����ġ�� �����.
			changeDir(fish_vec[fishNum].dir);
			continue;
		}
		else {
			// ������ �� �ִ�.
			if (fish_map[S_row_pos][S_column_pos] != EMPTY) {
				int targetFishNum = fish_map[S_row_pos][S_column_pos];
				changeTwoFishPos(fishNum, targetFishNum, fish_vec, fish_map);
			}
			else {
				int before_row_pos = fish_vec[fishNum].row_pos;
				int before_column_pos = fish_vec[fishNum].column_pos;
				fish_map[before_row_pos][before_column_pos] = EMPTY;
				// ���� ��ġ ��ɷ� ó��

				fish_map[S_row_pos][S_column_pos] = fishNum;
				fish_vec[fishNum].row_pos = before_row_pos;
				fish_vec[fishNum].column_pos = before_column_pos;
				//  fish NUm�� ���� ��ġ ����. ������ ���� ��ġ�� ����.

			}
			// ���� �ѹ��̶� ����Ǹ� Ż��.
			break;
		}
	}
}

void move_fishes(vector<Fish>& fish_vec, vector<vector<int>>& fish_map) {
	F(fishNum, 1, (8 + 1)) {
		if (fish_vec[fishNum].isAlive == true) {
			try_move_fish(fishNum, fish_vec, fish_map);
		}
	}
}
void DFS_move_fish_move_shark(int eatenSum, vector<Fish> fish_vec, vector<vector<int>> fish_map) {
	move_fishes(fish_vec, fish_map);
	// ������

	//move shark
	int distance = 1;
	while (true) {
		int S_row_pos = fish_vec[SHARK].row_pos + dir_R[fish_vec[SHARK].dir] * distance;
		int S_column_pos = fish_vec[SHARK].column_pos + dir_C[fish_vec[SHARK].dir] * distance;
		if ((S_row_pos < 0 || S_row_pos>3) || (S_column_pos < 0 || S_column_pos>3)) {
			// ��谪 ���� ���� ���ٸ�.
			break;
		}
		if (fish_map[S_row_pos][S_column_pos] != EMPTY) {
			// ��Ƹ԰�

			// ���� ��� ��ġ ����.
			int before_row_pos = fish_vec[SHARK].row_pos;
			int before_column_pos = fish_vec[SHARK].column_pos;
			int before_dir = fish_vec[SHARK].dir;

			int deadFishNum = fish_map[S_row_pos][S_column_pos];
			fish_map[fish_vec[SHARK].row_pos][fish_vec[SHARK].column_pos] = 0;
			// map ���� - ���� �����.

			fish_vec[deadFishNum].isAlive = false;
			fish_vec[SHARK] = Fish(S_row_pos, S_column_pos, fish_vec[deadFishNum].dir, true);

			// dfs
			DFS_move_fish_move_shark(eatenSum + deadFishNum, fish_vec, fish_map);

			// ����.

			fish_map[S_row_pos][S_column_pos] = deadFishNum;
			fish_map[before_row_pos][before_row_pos] = SHARK;
			// map �������� ����

			fish_vec[SHARK] = Fish(before_row_pos, before_column_pos, before_dir, true);
			fish_vec[deadFishNum].isAlive = true;
			//vector �������� ����.


		}
		distance++;
	}
	if (ans < eatenSum) {
		ans = eatenSum;
	}
	return;
}
int solution(vector<Fish> fish_vec, vector<vector<int>> fish_map) {
	// �� ����.

	//test code;
	//F(R, 0, 4) {
	//	F(C, 0, 4) {
	//		cout << fish_map[R][C] << " ";
	//	}
	//	cout << "\n";
	//}
	//

	//1. ����� �ʱ�ȭ - 0,0�� �̵��ؼ� �ִ� ����⸦ ��Ƹ���.
	int first_dead_fishNum = init_shark(fish_vec, fish_map);
	//������ �ޱ�.

	//2. ����� �̵� -> ����̵��� �ݺ�.
	DFS_move_fish_move_shark(first_dead_fishNum, fish_vec, fish_map);
	// �� ����.

	return ans;//test.
}

int main(void) {
	vector<Fish> fish_vec(17, Fish(-1,-1,-1,false));
	vector<vector<int>> fish_map(4, vector<int>(4, EMPTY));
	Input(fish_vec, fish_map);
	// ���������� �ޱ�..

	cout << solution(fish_vec, fish_map);
	// �� ����.
}