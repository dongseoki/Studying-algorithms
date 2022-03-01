#include <iostream>
#include <vector>
#define F(p,q,r) for(int p=q; p<r; p++)
using namespace std;


void paint_point(int R, int C, vector<vector<int>> & floor) {
	if (floor[R][C] != 0 && floor[R + 1][C] != 0 && floor[R][C + 1] != 0 && floor[R + 1][C + 1] != 0) {
		// 1or 2.
		floor[R][C] = 2;
		floor[R+1][C] = 2;
		floor[R][C+1] = 2;
		floor[R+1][C+1] = 2;
	}
}
int N;
int M;

bool check(vector<vector<int>>& floor) {
	F(R, 0, N) {
		F(C, 0, M) {
			if (floor[R][C] == 1) {
				return false;
			}

		}
	}

	return true;
}
int main() {
	int T;

	vector<string> answers;
	
	cin >> T;
	F(t_idx, 0, T) {

		cin >> N;
		cin >> M;
		vector<vector<int>> floor(N, vector<int>(M, 0));
		F(R, 0, N) {
			F(C, 0, M) {
				cin >> floor[R][C];

			}
		}


		F(R, 0, (N-1)) {
			F(C, 0, (M-1)) {
				paint_point(R, C, floor);

			}
		}
		// 최대한칠한다.

		if (check(floor) == true) {
			answers.push_back("YES\n");
		}
		else {
			answers.push_back("NO\n");
		}


		// 결과를 확인한다.
	}


	for (auto item : answers) {
		cout << item;
	}
	return 0;
}