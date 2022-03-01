#include <iostream>
#include <vector>
using namespace std;
int T;
int N;
int M;
int K;
int max_w_s = 0;
int ans = 0;
int w_s; //waste size
int d_r[4] = { 0,0,+1,-1 };
int d_c[4] = { +1,-1,0,0 };


void dfs(int r, int c, vector<vector <int>>& baechoobat, vector<vector <bool>>& visited) {
	visited[r][c] = true;
	int s_r = 0;
	int s_c = 0;
	for (int i = 0; i < 4; i++) {
		s_r = r + d_r[i];
		s_c = c + d_c[i];
		if (0 <= s_r && s_r < N && 0 <= s_c && s_c < M) {
			if (visited[s_r][s_c] == false && baechoobat[s_r][s_c] == 1) {
				dfs(s_r, s_c, baechoobat, visited);
			}
		}
	}
}

int main(void) {
	cin >> T;
	while (T > 0) {
		T--;
		ans = 0;
		cin >> N;
		cin >> M;
		cin >> K;
		vector<vector <int>> baechoobat(N, vector<int>(M, 0));

		vector<vector <bool>> visited(N, vector<bool>(M, false));

		for (int i = 0; i < K; i++) {
			int r;
			int c;
			cin >> r;
			cin >> c;
			baechoobat[r][c] = 1;
			//baechoobat[c-1][r-1] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == false && baechoobat[i][j] == 1) {
					visited[i][j] = true;
					ans++;
					dfs(i, j, baechoobat, visited);
				}
			}
		}
		cout << ans << "\n";
	}
	

}