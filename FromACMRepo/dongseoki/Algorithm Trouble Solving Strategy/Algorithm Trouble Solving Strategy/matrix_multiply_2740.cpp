#include <iostream>
#include <vector>
using namespace std;
void matrix_multiply(int N, int M, int K, int a_r, int a_c, int b_r, int b_c);
vector<vector<int>> b_matrix;
vector<vector<int>> a_matrix;
vector<vector<int>> c_matrix;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	int N;
	int M;
	cin >> N;
	cin >> M;
	a_matrix.assign(N + 1, vector<int>(M + 1, 0));
	//(N+1, vector<int>(M+1, 0)); // not use index 0.

	for (int i = 1; i <= a_matrix.size() - 1; i++) {
		for (int j = 1; j <= a_matrix[i].size() - 1; j++)
			cin >> a_matrix[i][j];
	}

	int M2;
	int K;
	cin >> M2;
	cin >> K;
	b_matrix.assign(M2 + 1, vector<int>(K + 1, 0));
	//(M2 + 1, vector<int>(K + 1, 0)); // not use index 0.

	for (int i = 1; i <= b_matrix.size() - 1; i++) {
		for (int j = 1; j <= b_matrix[i].size() - 1; j++)
			cin >> b_matrix[i][j];
	}

	c_matrix.assign(N + 1, vector<int>(K + 1, 0));

	matrix_multiply(N, M, K, 1, 1, 1, 1);

	//	cout << "hello" << "\n";
	for (int i = 1; i <= c_matrix.size() - 1; i++) {
		for (int j = 1; j <= c_matrix[i].size() - 1; j++)
			cout << c_matrix[i][j] << " ";
		cout << "\n";
	}
}

void matrix_multiply(int N, int M, int K, int a_r, int a_c, int b_r, int b_c) {
	//cout << "Count" << "\n";

	if (N < 1 || K < 1)
		return;
	if (N == 1 && K == 1) {
		for (int i = 0; i < M; i++) {
			c_matrix[a_r][b_c] += a_matrix[a_r][a_c + i] * b_matrix[b_r + i][b_c];
		}
		return;
	}

	//A: 1
	//	2 
	//	 K
	//B : 3 4 일때
	matrix_multiply(N / 2, M, K / 2, a_r, a_c, b_r, b_c); // 1*3
	matrix_multiply(N / 2, M, K - K / 2, a_r, a_c, b_r, b_c + K / 2);//1*4
	matrix_multiply(N - N / 2, M, K / 2, a_r + N / 2, a_c, b_r, b_c);//2*3
	matrix_multiply(N - N / 2, M, K - K / 2, a_r + N / 2, a_c, b_r, b_c + K / 2);//2*3
}