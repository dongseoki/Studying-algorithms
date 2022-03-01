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
vector<vector <int>> adjmap(51, vector<int>(51, 0)); // 정점의 최대 개수 1000
vector<vector <int>> adjlist(1);
vector<vector <bool>> visited(51, vector<bool>(51, false));
int w, h;

// 인접 행렬을 이용한 풀이
//https://sunnyholic.com/93

// 인접 리스트를 이용한 풀이
//https://m.blog.naver.com/PostView.nhn?blogId=metalingus58&logNo=221161057379&proxyReferer=https%3A%2F%2Fwww.google.com%2F

void DFS_Recursive_adjmatrix(int current_r, int current_c);
void DFS_Recursive_adjlist(int V);
void BFS_adjmatrix(int V);
void BFS_adjlist(int V);
int use_adj_matrix();
void use_adj_list();
int dr[8] = { -1,-1,-1,0 ,+1,+1,+1 ,0 };//동서남북
int dc[8] = { -1,0 ,+1,+1,+1 ,0,-1,-1 };
//012
//7 3
//654
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?
	

	use_adj_matrix();
	//use_adj_list();

}

int  use_adj_matrix(void) {

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> adjmap[i][j];
			}
		}

		visited.clear();
		visited.assign(51, vector<bool>(51, false));
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (adjmap[i][j] == 1 && visited[i][j] == false) {
					DFS_Recursive_adjmatrix(i, j);
					count++;
				}
					
			}
		}

		cout << count << '\n';
	}
}

void DFS_Recursive_adjmatrix(int current_r, int current_c) {
	visited[current_r][current_c] = true;

	// 내용 
	
	// 

	// 벡터의 크기..??
	for (int i = 0; i < 8; i++) {
		int search_r = current_r + dr[i];
		int search_c = current_c + dc[i];
		if(0<=search_r && search_r<h && 0<=search_c && search_c < w)
			if (adjmap[search_r][search_c] == 1 && visited[search_r][search_c] ==false) {
				DFS_Recursive_adjmatrix(search_r, search_c);
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
