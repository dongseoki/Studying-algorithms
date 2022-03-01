//https://www.acmicpc.net/problem/17779

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int  findMinDifference(int x, int y, int d1, int d2, const int & N, const vector<vector<int>>  & emap) {
	vector<int> sectpo(6, 0); // section populations
	vector<vector<int>> smap(N + 1, vector<int>(N + 1, 0));
	int errnum = 0;
	// index 0 사용 안함.
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if ((x - y) <= (r - c) && (r - c) <= (x - y + 2 * d1) 
				&& (x + y) <= (r + c) && (r + c) <= (x + y + 2 * d2)) {
				
				sectpo[5] += emap[r][c];
				smap[r][c] = 5;
				
			}// case 5..
			else if (1 <= r && r < (x + d1) && (1 <= c) && c <= y) {
				sectpo[1] += emap[r][c];
				smap[r][c] = 1;
			}

			else if (1 <= r && r <= (x + d2) && (y < c) && c <= N) {
				sectpo[2] += emap[r][c];
				smap[r][c] = 2;
			}
			else if ((x + d1) <= r && r <= N && (1 <= c) && c < (y - d1 + d2)) {
				sectpo[3] += emap[r][c];
				smap[r][c] = 3;
			}
			else if ((x + d2) < r && r <= N && (y - d1 + d2) <= c && c <= N) {
				
				sectpo[4] += emap[r][c];
				smap[r][c] = 4;
			}
		}
	}
	

	return  *max_element(sectpo.begin() + 1, sectpo.end()) - *min_element(sectpo.begin() + 1, sectpo.end());
}

int main(void) {
	int N;
	cin >> N;
	vector<vector<int>> emap(N + 1, vector<int>(N + 1, -1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> emap[i][j];
		}
	}


	int answer = numeric_limits<int>::max(); //2100000000;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (d1 >= 1 && d2 >= 1 && (x + d1 + d2) <= N && 1 <= (y - d1) && (y + d2) <= N) {
						int dist = findMinDifference(x, y, d1, d2, N, emap);
						if (answer > dist) {
							answer = dist;
						}
					}
				}
			}
		}
	}

	cout << answer << "\n";
}