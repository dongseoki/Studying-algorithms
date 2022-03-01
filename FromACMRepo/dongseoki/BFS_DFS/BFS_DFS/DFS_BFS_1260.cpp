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
vector<vector <int>> adjmap(1001, vector<int>(1001, 0)); // 정점의 최대 개수 1000
vector<vector <int>> adjlist(1);
vector<bool> visited(1001, false);
int N, M, V;

// 인접 행렬을 이용한 풀이
//https://sunnyholic.com/93

// 인접 리스트를 이용한 풀이
//https://m.blog.naver.com/PostView.nhn?blogId=metalingus58&logNo=221161057379&proxyReferer=https%3A%2F%2Fwww.google.com%2F

void DFS_Recursive_adjmatrix(int V);
void DFS_Recursive_adjlist(int V);
void BFS_adjmatrix(int V);
void BFS_adjlist(int V);
void use_adj_matrix();
void use_adj_list();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?
	
	cin >> N >> M >> V;

	//use_adj_matrix();
	use_adj_list();

}

void use_adj_matrix(void) {
	
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		adjmap[from][to] = 1;
		adjmap[to][from] = 1;
	}

	DFS_Recursive_adjmatrix(V);
	cout << '\n';
	// 초기화.
	visited.clear();
	visited.assign(1001, false);
	//
	BFS_adjmatrix(V);
}

void use_adj_list(void) {
	adjlist.resize(N+1);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		//adjlist.
		adjlist[from].push_back(to);
		adjlist[to].push_back(from);
	}
	//정점 번호 정렬
	for (int i = 1; i <= N; i++) {
		sort(adjlist[i].begin(), adjlist[i].end());
	}

	DFS_Recursive_adjlist(V);
	cout << '\n';
	// 초기화.
	visited.clear();
	visited.assign(1001, false);
	//
	BFS_adjlist(V);

}

void DFS_Recursive_adjlist(int V) {
	visited[V] = true;

	// 내용 
	cout << V << " ";
	// 
	
	int size = adjlist[V].size();
	for (int i = 0; i < size; i++) {
		int node = adjlist[V][i];
		if (visited[node] == false)
			DFS_Recursive_adjlist(node);
	}
}

void BFS_adjlist(int V) {
	queue<int> q;
	q.push(V);
	visited[V] = true;
	while (!q.empty()) {
		int V = q.front();
		q.pop();

		// 내용
		cout << V << " ";
		//

		//q.pop 의 반환형이 void 이다.
		int size = adjlist[V].size();
		for (int i = 0; i < size; i++) {
			int node = adjlist[V][i];
			if (visited[node] == false) {
				q.push(node);
				visited[node] = true;
			}
		}

	}

}

void DFS_Recursive_adjmatrix(int V) {
	visited[V] = true;

	// 내용 
	cout << V << " ";
	// 

	// 벡터의 크기..??
	for (int i = 1; i <= N; i++) {
		if (adjmap[V][i] == 1) {
			if (visited[i] == false)
				DFS_Recursive_adjmatrix(i);
		}
	}
}

void BFS_adjmatrix(int V) {
	queue<int> q;
	q.push(V);
	visited[V] = true;
	while (!q.empty()) {
		int V = q.front();
		q.pop();

		// 내용
		cout << V << " ";
		//

		//q.pop 의 반환형이 void 이다.
		for (int i = 1; i <= N; i++) {
			if (adjmap[V][i] == 1) {
				if (visited[i] == false) {
					q.push(i);
					visited[i] = true;
				}
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
