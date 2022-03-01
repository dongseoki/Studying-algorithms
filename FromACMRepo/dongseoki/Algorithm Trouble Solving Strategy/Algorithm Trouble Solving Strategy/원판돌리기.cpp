#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define F(p,q,r) for(int p=q; p<r; p++)
#define INVALID_NUMBER 999999
// 9 �� 6��.
using namespace std;


int N, M, T;
bool flag = false;

void turn(int xi, int di, int ki, vector<vector<int>>& disks, vector<int>& upidx_v) {
	F(d_idx, 1, (N + 1)) {
		if (d_idx % xi != 0) {
			continue;
		}

		// d_idx % xi  == 0 �� ���, �� ��� �ΰ��!

		int pn = 0; // plus or minus;
		if (di == 0) {
			// �ð� ����.
			pn = -1;
		}
		else {
			// �ð� �ݴ� ����..
			pn = +1;
		}

		upidx_v[d_idx] = (upidx_v[d_idx] + M + pn * ki) % M;
		// �ش� �������� ki ��ŭ ȸ��. ������ �ش��ϴ� up idx�� ����.

	}
}



void real_adj_remove(int i, int j, int num, vector<vector<int>>& disks, vector<int>& upidx_v, vector<vector<bool>>& visited) {

	// �湮 ���θ� true ��..


	//  �̸� ���� �޾Ƶ���. �ٲ� ���� ������.

	int l_idx = (j + M - 1) % M;//left idx. �ش� �ε�����  �ð� 12�� ���⿡ �ΰԲ� ������ ������ �� ����.
	// �ƴ���, ������ �ε�����, ���� ���� �ε���.

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

	// (i, j)�� (i, j-1), (i, j+1)�� �����ϴ�.
	//(1 �� j �� M-2)
	// 1. ���� ���� �� ������ ����.


	int dif_v; // ���� �� diffrence value
	// i+1 �� �۾ƾߵ�. 

	//2-1 ���� �ε����� ū ���ǰ��� ��.
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

	//2-2 ���� �ε����� ���� ���ǰ��� ��
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
	// 2. �ٸ� ���� ���� ������ ����.
}
bool adj_remove(vector<vector<int>>& disks, vector<int>& upidx_v) {
	flag = false;
	// �ʱ�ȭ.

	// X ǥ�� ��� -1 �� ��� �Ѵ�.
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
				// -1 �� �ƴϴ� ��� �� ���� ���� �ִ� ��.
				// ���ǿ� ���� ���� �ٲ� ���� �ֱ���. .. �ƹ��� ���ص� ���� ���� ���ϴ� ���� �ʿ�.
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
			// ������ �ƹ� �� ����.
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

			// ������ �ƹ� �� ����.
		}
	}
	return sum;
}
int main(void) {

	cin >> N;
	cin >> M;
	cin >> T;


	// �׳� ���� 1�� ���Ǻ��� �ִٰ� �����غ���!
	vector<vector<int>> disks(N + 1, vector<int>(M, INVALID_NUMBER));
	// �ʱ�ȭ.

	vector<int> upidx_v(N + 1, 0);  // 0�� ���� �̷��� ����.
	//  �ʱ⿡ ��� ����� idx�� 0�̴�.


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

			// ���� ���� �����ٸ�.
			update_disks_data(disks);
			//�� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.
		}
	}

	cout << sum_of_disks_numbers(disks);

}