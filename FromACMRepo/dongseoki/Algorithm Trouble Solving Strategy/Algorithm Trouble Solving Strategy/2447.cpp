#include <iostream>
#include <vector>
using namespace std;

void DC(int r, int c, int N, vector<vector<char>>& stars) {
	if (N == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				stars[r + i][c + j] = '*';
			}
		}
		stars[r + 1][c + 1] = ' ';
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					continue;
				DC(r+N/3 *i, c+ N / 3 * j, N/3, stars);
			}
		}
	}
}

int main(void) {
	int N;
	cin >> N;
	vector<vector<char>> stars(N, vector<char>(N, ' ')); // 공백 안넣었다고 틀렸다.. 확인할것.

	DC(0, 0, N, stars);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << stars[i][j];
		}
		cout << "\n";
	}
}