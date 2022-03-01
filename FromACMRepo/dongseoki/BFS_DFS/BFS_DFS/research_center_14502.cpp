#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int max_safe_area = -1;
int wallcase = 0;
int N, M;
vector<vector<int>> copiedmap(8, vector<int>(8, -1));
vector<vector<int>> adjmap(9, vector<int>(9, -1));
vector<vector<int>> savedmap(8, vector<int>(8, -1));
vector<vector<bool>> visited(8, vector<bool>(8, false));
int dr[4] = { +1,-1,0,0 };
int dc[4] = { 0,0,-1,+1 };

void spread_virus(int current_r, int current_c) {//, vector<vector<int>> & copiedmap
	visited[current_r][current_c] = true;

	copiedmap[current_r][current_c] = 2;

	for (int i = 0; i < 4; i++) {
		int search_r = current_r + dr[i];
		int search_c = current_c + dc[i];
		if (0 <= search_r && search_r < N && 0 <= search_c && search_c <= M)
			if (copiedmap[search_r][search_c] == 0 && visited[search_r][search_c] == false)
				spread_virus(search_r, search_c);//, copiedmap
	}
}
void show_map(vector<vector<int>> map) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j]<<" ";
		}
		cout << "\n";
	}
}


void infection_start(void) {//vector<vector<int>> & copiedmap
	wallcase++;

	int count = 0;
	//
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copiedmap[i][j] == 2 && visited[i][j] == false) {
				spread_virus(i, j);//, copiedmap
			}
		}
	}
	//show_map(copiedmap);
	// 안전영역을 계산한다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copiedmap[i][j] == 0)
				count++;
		}
	}


	//최대값을 갱신한다.
	if (max_safe_area < count) {
		max_safe_area = count;
		savedmap = copiedmap;
	}
		
}

void recursive_building_walls(int walls) {
	if (walls >= 3) {
		// 방문 배열 초기화.
		//visited.clear();
		visited.assign(8, vector<bool>(8, false));

		// 현재 배열 값을 복사해서 넘겨주자.(처음 벽,바이러스의 초기화를 위해)
		copiedmap = adjmap;
		infection_start();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (adjmap[i][j] == 0) {
				adjmap[i][j] = 1;
				recursive_building_walls(walls + 1);
				adjmap[i][j] = 0;
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> adjmap[i][j];
	}
	recursive_building_walls(0);
	cout << max_safe_area;
	//cout << "\n";
	//cout << "wallcase :" << wallcase << "\n";
	//cout << "savedmap" << "\n";
	//show_map(savedmap);
	
	//use_adj_list();

}