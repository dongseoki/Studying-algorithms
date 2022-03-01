#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int dr[4] = { 0,0,+1,-1 };
int dc[4] = { +1,-1,0,0 };
// 동서남북.

int main(void) {
	int N;
	int M;
	scanf("%d %d", &N, &M);
	//출발지 0,0 목적지. N-1, M-1.
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<pair<pair<int, int> , pair<int, int>>> q;
	// 첫번쨰 요소. 점.
	// 두번째 요소. 지금까지 거리, 벽을 뚫었나 유무 안뚫었으면 0, 뚫었으면1.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> pos = q.front(); //position 현재 위치.
		q.pop();
		if (pos.first.first == N - 1 && pos.first.second == M - 1) {
			printf("%d\n", pos.second.first);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int sr = pos.first.first + dr[i];
			int sc = pos.first.second + dc[i];

			if (0 <= sr && sr <= N - 1 && 0 <= sc && sc <= M - 1) {
				if (visited[sr][sc] == false ) {
					if (map[sr][sc] == 1) {
						if (pos.second.second == 0)
							pos.second.second = 1;
						else
						{
							continue;
						}
					}
					visited[sr][sc] = true;
					q.push(make_pair(make_pair(sr, sc), make_pair(pos.second.first + 1, pos.second.second)));
				}
			}
		}
	}

	printf("-1\n");


}