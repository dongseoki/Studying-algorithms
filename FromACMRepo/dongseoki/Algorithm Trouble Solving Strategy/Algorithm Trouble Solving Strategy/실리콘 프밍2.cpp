#include <string>
#include <iostream>
#include <vector>
using namespace std;

int check(vector<vector<int>>& office, int i, int j, int k) {

	int result = 0;
	for (int r_count = 0; r_count < k; r_count++) {
		for (int c_count = 0; c_count < k; c_count++) {
			if (office[i + r_count][j + c_count] == 1) {
				result++;
			}
		}
	}

	return result;
}

int solution(vector<vector<int>> office, int k) {
	int answer = 0;
	int N = office[0].size();
	//cout << N;
	for (int i = 0; (i + k) < N+1; i++) {
		for (int j = 0; (j + k) < N+1; j++) {
			int t = check(office, i, j, k);
			if (answer < t) {
				answer = t;
			}
		}
	}


	return answer;
}

int main(void) {
	int N;
	cin >> N;
	int k;
	cin >> k;
	vector<vector<int>> office(N, vector<int>(N,0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> office[i][j];
		}
	}
	int result = solution(office, k);
	cout << result;
}