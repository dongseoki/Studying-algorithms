#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define F(p,q,r) for(int p=q; p<r; p++)
#define INVALID_NUMBER 999999
// 9 가 6개.
using namespace std;


int N, M, T;
bool flag = false;

void turn(int xi, int di, int ki, vector<vector<int>>& disks, vector<int>& upidx_v) {
	F(d_idx, 1, (N + 1)) {
		if (d_idx % xi != 0) {
			continue;
		}

		// d_idx % xi  == 0 인 경우, 그 배수 인경우!

		int pn = 0; // plus or minus;
		if (di == 0) {
			// 시계 방향.
			pn = -1;
		}
		else {
			// 시계 반대 방향..
			pn = +1;
		}

		upidx_v[d_idx] = (upidx_v[d_idx] + M + pn * ki) % M;
		// 해당 방향으로 ki 만큼 회전. 했을때 해당하는 up idx를 갱신.

	}
}



void real_adj_remove(int i, int j, int num, vector<vector<int>>& disks, vector<int>& upidx_v, vector<vector<bool>>& visited) {

	// 방문 여부를 true 로..


	//  미리 값을 받아두자. 바뀔 수도 있으니.

	int l_idx = (j + M - 1) % M;//left idx. 해당 인덱스를  시계 12시 방향에 두게끔 원판을 놓았을 때 기준.
	// 아니지, 인접한 인덱스중, 값이 작은 인덱스.

	int r_idx = (j + M + 1) % M;

	if (visited[i][l_idx] == false && num == disks[i][l_idx]) {
		visited[i][l_idx] = true;

		disks[i][j] = INVALID_NUMBER;
		disks[i][l_idx] = INVALID_NUMBER;
		flag = true;

		real_adj_remove(i, l_idx, num, disks, upidx_v, visited);
	}

	if (visited[i][r_idx] == false && num == disks[i][r_idx]) {
		visited[i][r_idx] = true;

		disks[i][j] = INVALID_NUMBER;
		disks[i][r_idx] = INVALID_NUMBER;
		flag = true;
		real_adj_remove(i, r_idx, num, disks, upidx_v, visited);
	}

	// (i, j)는 (i, j-1), (i, j+1)과 인접하다.
	//(1 ≤ j ≤ M-2)
	// 1. 같은 원판 내 인접성 유무.


	int dif_v; // 차이 값 diffrence value
	// i+1 이 작아야됨. 

	//2-1 보다 인덱스가 큰 원판과의 비교.
	if (i <= (N - 1)) {
		dif_v = j - upidx_v[i];
		int above_col_idx = (upidx_v[i + 1] + dif_v + M) % M;
		if (visited[i + 1][above_col_idx] == false && num == disks[i + 1][above_col_idx]) {
			visited[i + 1][above_col_idx] = true;

			disks[i][j] = INVALID_NUMBER;
			disks[i + 1][above_col_idx] = INVALID_NUMBER;
			flag = true;
			real_adj_remove(i + 1, above_col_idx, num, disks, upidx_v, visited);
		}
	}

	//2-2 보다 인덱스가 작은 원판과의 비교
	if (2 <= i) {
		dif_v = j - upidx_v[i];
		int below_col_idx = (upidx_v[i - 1] + dif_v + M) % M;
		if (visited[i - 1][below_col_idx] == false && num == disks[i - 1][below_col_idx]) {
			visited[i - 1][below_col_idx] = true;

			disks[i][j] = INVALID_NUMBER;
			disks[i - 1][below_col_idx] = INVALID_NUMBER;
			flag = true;
			real_adj_remove(i - 1, below_col_idx, num, disks, upidx_v, visited);
		}
	}
	// 2. 다른 원판 사이 인접성 유무.
}
bool adj_remove(vector<vector<int>>& disks, vector<int>& upidx_v) {
	flag = false;
	// 초기화.

	// X 표시 대신 -1 로 대신 한다.
	vector<vector<bool>> visited(N + 1, vector<bool>(M, false));
	F(i, 1, (N + 1)) {
		F(j, 0, M) {
			if (visited[i][j] == false && disks[i][j] != INVALID_NUMBER) {
				visited[i][j] = true;
				int num = disks[i][j];
				real_adj_remove(i, j, num, disks, upidx_v, visited);
			}



		}
	}

	return flag;
}

void update_disks_data(vector<vector<int>>& disks) {
	int sum = 0;
	int count_n = 0;
	F(i, 1, (N + 1)) {
		F(j, 0, M) {
			int value = disks[i][j];
			if (value == INVALID_NUMBER) {
				continue;
			}
			else {
				// -1 이 아니다 라는 것 실제 값이 있는 것.
				// 원판에 적힌 수가 바뀔 수가 있구만. .. 아무리 더해도 도달 하지 못하는 값이 필요.
				sum += value;
				count_n++;
			}

		}
	}

	double avg_n = (double)sum / count_n;
	F(i, 1, (N + 1)) {
		F(j, 0, M) {
			int value = disks[i][j];
			if (value == INVALID_NUMBER) {
				continue;
			}
			if (avg_n < value) {
				disks[i][j]--;
			}
			if (avg_n > value) {
				disks[i][j]++;
			}
			// 같으면 아무 짓 안함.
		}
	}
}



int sum_of_disks_numbers(vector<vector<int>>& disks) {
	int sum = 0;

	F(i, 1, (N + 1)) {
		F(j, 0, M) {
			int value = disks[i][j];
			if (value == INVALID_NUMBER) {
				continue;
			}
			sum += value;

			// 같으면 아무 짓 안함.
		}
	}
	return sum;
}
int main(void) {

	cin >> N;
	cin >> M;
	cin >> T;


	// 그냥 전부 1번 원판부터 있다고 가정해보자!
	vector<vector<int>> disks(N + 1, vector<int>(M, INVALID_NUMBER));
	// 초기화.

	vector<int> upidx_v(N + 1, 0);  // 0번 원판 이런건 없다.
	//  초기에 모든 상단의 idx는 0이다.


	F(i, 1, (N + 1)) {
		F(j, 0, M) {
			cin >> disks[i][j];
		}
	}

	F(i, 0, T) {
		int xi, di, ki;
		cin >> xi;
		cin >> di;
		cin >> ki;
		turn(xi, di, ki, disks, upidx_v);
		bool condition = adj_remove(disks, upidx_v);
		if (condition == false) {

			// 인접 성이 없었다면.
			update_disks_data(disks);
			//는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
		}
	}

	cout << sum_of_disks_numbers(disks);

}