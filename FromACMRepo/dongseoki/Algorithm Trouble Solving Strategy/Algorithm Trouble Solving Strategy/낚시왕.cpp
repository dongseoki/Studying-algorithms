#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define F(p,q,r) for(int p=q; p<r;p++)
using namespace std;

int sh_count;

class Shark {
public :
	bool alive;
	int r;
	int c;
	int s;
	int d;
	int z;

	Shark() {
		this->alive = true;
	}
};
int R, C, M;
vector<Shark> sh_vec;
vector<int> reverse_d = { 0,2,1,4,3 };

vector<int> direction_row = { 0,-1,+1,0,0 };
vector<int> direction_column = { 0,0,0,+1, -1 };

int answer;
void push_shark_into_te(vector<Shark>& sh_vec, vector<vector<vector<int>>> & fishing_te) {
	F(s_idx, 0, M) {
		Shark sh = sh_vec[s_idx];
		fishing_te[sh.r][sh.c].push_back(s_idx);
	}
}
void transform_shark(vector<Shark>& sh_vec) {
	F(s_idx, 0, M) {
		Shark& sh = sh_vec[s_idx];

		if (sh.r == 1 && sh.d == 2)
			sh.d = 1;
		if (sh.r == R && sh.d == 1)
			sh.d = 2;
		if (sh.c == 1 && sh.d == 3)
			sh.d = 4;
		if (sh.c == C && sh.d == 4)
			sh.d = 3;
		// 끝에 있으면 방향을 바꿔주기.

		if (sh.d <= 2) {
			sh.s = sh.s % (2 * (R - 1));
		}// 주기 를 이용하여 , 상어의 속도를 줄이자.
		else {
			sh.s = sh.s % (2 * (C - 1));
		}
	}
}


void catch_shark(int K_idx, vector<Shark>& sh_vec, vector<vector<vector<int>>>& fishing_te) {
	F(G_idx, 1, (R + 1)) {
		if (fishing_te[G_idx][K_idx].size() > 1) {
			cout<< "error\n";
			return ;
		}
		else if (fishing_te[G_idx][K_idx].size() == 1) {
			int sh_idx = fishing_te[G_idx][K_idx].back();
			if (sh_vec[sh_idx].alive == false)
				continue;
			sh_vec[sh_idx].alive = false;
			sh_count--;
			answer += sh_vec[sh_idx].z;
			fishing_te[G_idx][K_idx].pop_back();
			break;
		}
	}
}

int find_item(const vector<int>& v1, int item) {

	F(idx, 0, v1.size()) {
		if (v1[idx] == item)
			return idx;
	}
	return -1;
}

void move_shark(vector<Shark>& sh_vec, vector<vector<vector<int>>>& fishing_te) {
	F(s_idx, 0, M) {
		
		Shark& sh = sh_vec[s_idx];
		
		//벡터에서 상어를 
		if (sh.alive == false) {
			continue;
		}// 죽은 상어 무시하기.

		//if (fishing_te[sh.r][sh.c].size() > 1) {
		//	cout << "error\n";
		//	return;
		//}

		int found_idx = find_item(fishing_te[sh.r][sh.c], s_idx);
		fishing_te[sh.r][sh.c].erase(fishing_te[sh.r][sh.c].begin() + found_idx);
		//fishing_te[sh.r][sh.c].clear();
		// 위치에 있는 물고기를 삭제.

		int search_row = sh.r + direction_row[sh.d] * sh.s;
		int search_column = sh.c + direction_column[sh.d] * sh.s;

		F(again, 0, 2) {
			if (search_row > R) {
				search_row = R - abs(search_row - R);
				sh.d = reverse_d[sh.d];
			}
			if (search_row < 1) {
				search_row = 1 + abs(search_row - 1);
				sh.d = reverse_d[sh.d];
			}
			if (search_column > C) {
				search_column = C - abs(search_column - C);
				sh.d = reverse_d[sh.d];
			}
			if (search_column < 1) {
				search_column = 1 + abs(search_column  - 1);
				sh.d = reverse_d[sh.d];
			}
		}		// 상어가 이동한다.		


		sh.r = search_row;
		sh.c = search_column;

		fishing_te[sh.r][sh.c].push_back(s_idx);
		// 움직인 위치에 상어를 추가.
		
	}

}
bool cmp(int idx1, int idx2) {
	return sh_vec[idx1].z > sh_vec[idx2].z;
}

void remove_same_pos_shark(vector<Shark>& sh_vec, vector<vector<vector<int>>>& fishing_te) {
	F(r_idx, 1, (R + 1)) {
		F(c_idx, 1, (C + 1)) {
			if (fishing_te[r_idx][c_idx].size() > 1) {

				sort(fishing_te[r_idx][c_idx].begin(), fishing_te[r_idx][c_idx].end(), 
					[sh_vec](int idx1, int idx2)-> int
					{
						return sh_vec[idx1].z > sh_vec[idx2].z;
					}
				);

				//sort(fishing_te[r_idx][c_idx].begin(), fishing_te[r_idx][c_idx].end(), cmp);

				int live_idx = fishing_te[r_idx][c_idx][0];
\
				F(K, 1, fishing_te[r_idx][c_idx].size()) {
					sh_vec[fishing_te[r_idx][c_idx][K]].alive = false;
				}
				// 0제외 다 false.
				fishing_te[r_idx][c_idx].clear();
				fishing_te[r_idx][c_idx].push_back(live_idx);

			}
		}
	}
}

void print_shark_move(vector<Shark> sh_vec) {
	vector<vector<char>> p_map(R + 1, vector<char>(C + 1, 'O'));

	F(sh_idx, 0, sh_vec.size()) {
		Shark sh = sh_vec[sh_idx];
		if (sh.alive == false)
			p_map[sh.r][sh.c] = 'X';
		else
			p_map[sh.r][sh.c] = 'A' + sh_idx;
	}

	F(r_idx, 1, (R+1)) {
		F(c_idx, 1, (C + 1)) {
			cout << p_map[r_idx][c_idx]<<" ";
		}
		cout << "\n";
	}
	cout << "-----------------------\n";
}
void print_shark_status(vector<Shark> sh_vec) {
	cout << "No\tAL\tR\tC\tS\tD\tZ\n\n";
	F(sh_idx, 0, sh_vec.size()) {
		Shark sh = sh_vec[sh_idx];
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", sh_idx, sh.alive, sh.r, sh.c, sh.s, sh.d, sh.z);
	}
	cout << "----------------------------------------\n\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R;
	cin >> C;
	cin >> M;
	sh_count = M;
	//vector<Shark> sh_vec(M, Shark());
	sh_vec.assign(M, Shark());
	F(s_idx, 0, M) {
		Shark& sh = sh_vec[s_idx];
		//scanf("%d %d %d %d %d", &sh.r, &sh.c, &sh.s, &sh.d, &sh.z);
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sh.r = r;
		sh.c = c;
		sh.s = s;
		sh.d = d;
		sh.z = z;
	}

	vector<vector<vector<int>>> fishing_te(R + 1, vector<vector<int>>(C + 1, vector<int>()));
	// index 0 는 안 씀.

	push_shark_into_te(sh_vec, fishing_te);
	//낙시터에 상어 인덱스를 넣자.

	transform_shark(sh_vec);
	// 끝에 있는 상어 방향 바꿔 주기와 상어의 속도를 줄이기.

	F(K_idx, 1, (C + 1)) {
		// 낙시왕이 움직임.
		if (sh_count <= 0) {
			break;
		}
		catch_shark(K_idx, sh_vec, fishing_te);
		// 땅과 제일 가까운 상어를 잡는다.
		move_shark(sh_vec, fishing_te);
		// 상어 이동.

		remove_same_pos_shark(sh_vec, fishing_te);
		// 같은 위치에 있는 상어는 큰놈이 작은 놈을 잡아 죽인다.
	}
	
	cout << answer;
}