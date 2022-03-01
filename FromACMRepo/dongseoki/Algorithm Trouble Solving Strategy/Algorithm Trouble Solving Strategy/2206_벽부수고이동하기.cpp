#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int dr[4] = { 0,0,+1,-1 };
int dc[4] = { +1,-1,0,0 };
// ��������.

int main(void) {
	int N;
	int M;
	scanf("%d %d", &N, &M);
	//����� 0,0 ������. N-1, M-1.
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<pair<pair<int, int> , pair<int, int>>> q;
	// ù���� ���. ��.
	// �ι�° ���. ���ݱ��� �Ÿ�, ���� �վ��� ���� �ȶվ����� 0, �վ�����1.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> pos = q.front(); //position ���� ��ġ.
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