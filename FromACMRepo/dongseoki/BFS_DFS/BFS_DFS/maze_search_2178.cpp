// BFS_DFS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//https://www.acmicpc.net/problem/1260

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//[출처] 백준 1260번 C++ | 작성자 컴공맨


using namespace std;
vector<vector <int>> adjmap(101, vector<int>(101, 0)); // 정점의 최대 개수 1000
vector<vector <bool>> visited(101, vector<bool>(101,false));
vector<vector <int>> D(101, vector<int>(101, -1));
vector < vector <pair <int, int>>> P(101, vector<pair<int, int>>(101, make_pair(-1,-1)));
int dr[4] = { +1,-1,0,0 };
int dc[4] = { 0,0,-1,+1 };
int N, M;

// 인접 행렬을 이용한 풀이
//https://sunnyholic.com/93

// 인접 리스트를 이용한 풀이
//https://m.blog.naver.com/PostView.nhn?blogId=metalingus58&logNo=221161057379&proxyReferer=https%3A%2F%2Fwww.google.com%2F

void BFS_adjmatrix(int current_r, int current_c);
void use_adj_matrix();
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?
	//https://eine.tistory.com/entry/CC-%EC%9E%85%EC%B6%9C%EB%A0%A5-%EB%B0%A9%EB%B2%95%EC%97%90-%EB%94%B0%EB%A5%B8-%EC%86%8D%EB%8F%84-%EC%A0%95%EB%A6%AC


	scanf("%d %d", &N, &M);

	use_adj_matrix();
	//use_adj_list();

}

void show_matrix(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%1d", adjmap[i][j]);
		printf("\n");
	}
}

void use_adj_matrix(void) {

	for (int i = 0; i < N; i++) {
		for(int j=0;j<M;j++)
			scanf("%1d", &adjmap[i][j]);
	}
	//show_matrix();
	//DFS_Recursive_adjmatrix(V);
	//cout << '\n';
	// 초기화.
	BFS_adjmatrix(0,0);
}

void BFS_adjmatrix(int current_r, int current_c) {
	queue<pair<int, int>> q;

	D[current_r][current_c] = 0;
	P[current_r][current_c] = make_pair(current_r, current_c);

	q.push(make_pair(current_r, current_c));
	visited[current_r][current_c] = true;

	while (!q.empty()) {
		pair<int, int> V = q.front();
		q.pop();

		// 내용
		if (V.first == N-1 && V.second == M-1) {
			printf("%d", D[V.first][V.second] +1);
			return;
		}
			
		//

		//q.pop 의 반환형이 void 이다.
		for (int i = 0; i < 4; i++) {
			int search_r = V.first + dr[i];
			int search_c = V.second + dc[i];
			if (0 <= search_r && search_r < N && 0 <= search_c && search_c < M)
				if (adjmap[search_r][search_c] == 1 && visited[search_r][search_c] == false) {
					//DFS_Recursive_adjmatrix(search_r, search_c);
					q.push(make_pair(search_r, search_c));

					visited[search_r][search_c] = true;

					D[search_r][search_c] = D[V.first][V.second] + 1;
					P[search_r][search_c] = make_pair(V.first, V.second);
				}
		}

	}
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
