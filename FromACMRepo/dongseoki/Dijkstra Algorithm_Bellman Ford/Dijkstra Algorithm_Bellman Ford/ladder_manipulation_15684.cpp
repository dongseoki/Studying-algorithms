#include <iostream>
#include <vector>


using namespace std;

void printmap(vector<vector<int>>& l_t) {
	cout << "map state\n";
	for (int i = 1; i < l_t.size(); i++) {
		for (int j = 1; j < l_t[0].size(); j++)
			cout << l_t[i][j] << " ";
		cout << "\n";
	}
	cout << "-------------------\n";
}

bool adjcheck(int row, int col, vector<vector<int>>& l_t, int N) {

	if (l_t[row][col] == 1)
		return true;

	if(col-1>=1)
		if (l_t[row][col - 1] == 1)
			return true;
	if(col+1<=N-1)
		if (l_t[row][col + 1] == 1)
			return true;

	return false;
}

bool riding_ladders(vector<vector<int>> &l_t, int N, int H) {
	//MRL => Max Row Line
	//for ������ ���μ��� �ִ´�.
	// ��ٸ��� �¿�� ���� ����
	// ��ΰ� ���� ���ٸ�
	// ������ ��ȯ�Ѵ�.
	// �ƴϸ�(����쿡 ����) false�� ��ȯ�Ѵ�.
	//cout << "N:" << N << "\n";
	for (int col = 1; col <= N; col++) {
		int now_col = col;
		for (int row = 1; row <= H; row++) {
			if(1<=now_col-1&& now_col - 1<=N-1) // left
				if (l_t[row][now_col - 1]) {
					now_col--;
					continue;
				}
			if(1 <= now_col && now_col <= N - 1) //right
				if(l_t[row][now_col])
					now_col++;

		}
		//cout << "now_col/col" << now_col << ", " << col << "\n";
		if (now_col != col)
			return false;
	}
	return true;
}

void addline(int count, int obj, vector<vector<int>>& l_t, int N, int H) {
	//MRL => Max Row Line
	//for ������ ���μ��� �ִ´�.
	// ��ٸ��� �¿�� ���� ����
	// ��ΰ� ���� ���ٸ�
	// ������ ��ȯ�Ѵ�.
	// �ƴϸ�(����쿡 ����) false�� ��ȯ�Ѵ�.

	if (count == obj) {
		//printmap(l_t);
		if (riding_ladders(l_t, N,H) == true) {
			cout << obj << "\n";
			exit(0);
		}
		return ;
	}
	if (count > obj) {
		return ;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (adjcheck(i,j,l_t,N))
				continue;
			l_t[i][j] = 1;
			addline(count + 1, obj, l_t, N, H);
			l_t[i][j] = 0;
		}
	}
	return;
}


int main(void) {
	int N; // ���μ�����
	int M; // ���μ� ����
	int H; // ���μ��� ���� �� �ִ� ��ġ ����
	cin >> N;
	cin >> M;
	cin >> H;
	vector<vector<int>> l_t(H+1, vector<int>(N, 0)); 
	//l_t�� ladder_table �� ����.
	// index 0�� ������. �׸��� H�� �������μ��� �������� �ؼ� ������ H-1 �̴�.
	int row;
	int col;
	for (int i = 0; i < M; i++) {
		cin >> row;
		cin >> col;
		l_t[row][col] = 1;
	}

	for (int i = 0; i <= 3;i++) {
		addline(0, i, l_t, N, H);
	}
	cout << -1<<"\n";
	return 0;

	//cout << "success\n";
}
