// acm_4_tree_and_division_comquer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
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

	for (int  i = 1; i <= a_matrix.size()-1; i++) {
		for (int j = 1; j <= a_matrix[i].size()-1; j++)
			cin >> a_matrix[i][j];
	}

	int M2;
	int K;
	cin >> M2;
	cin >> K;
	b_matrix.assign(M2 + 1, vector<int>(K + 1, 0));
	//(M2 + 1, vector<int>(K + 1, 0)); // not use index 0.

	for (int i = 1; i <= b_matrix.size()-1; i++) {
		for (int j = 1; j <= b_matrix[i].size()-1; j++)
			cin >> b_matrix[i][j];
	}
	
	c_matrix.assign(N + 1, vector<int>(K + 1, 0));

	matrix_multiply(N, M, K, 1, 1, 1, 1);

//	cout << "hello" << "\n";
	for (int i = 1; i <= c_matrix.size() - 1; i++) {
		for (int j = 1; j <= c_matrix[i].size() - 1; j++)
			cout << c_matrix[i][j]<<" ";
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
	matrix_multiply(N / 2, M, K - K / 2, a_r, a_c, b_r, b_c+K/2);//1*4
	matrix_multiply(N-N / 2, M, K / 2, a_r+N/2 , a_c, b_r, b_c);//2*3
	matrix_multiply(N - N / 2, M,K- K / 2, a_r + N / 2, a_c, b_r, b_c+K/2);//2*3
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
