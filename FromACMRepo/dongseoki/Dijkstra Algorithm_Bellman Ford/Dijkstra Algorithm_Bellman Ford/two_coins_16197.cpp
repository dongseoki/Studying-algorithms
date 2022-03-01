#include <iostream>
#include <vector>
#include <utility>
#pragma warning(disable:4996)

using namespace std;
vector<vector<char>> map(20, vector<char>(20,0));
int N;
int M;
int dr[4] = { 0,0,+1,-1 };
int dc[4] = { +1,-1,0,0 };
pair<int, int> p[2];

void printmap(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
			//cout << "t";
		}
		cout << "\n";
	}
}

bool onlyonedrop(void) {
	bool state[2];
	for (int k = 0; k < 2; k++) {
		if (0 <= p[k].first && p[k].first < N && 0 <= p[k].second && p[k].second < M)
			state[k] = true;
	}
	if (state[0] != state[1]) // 둘중 하나만 true면 즉 서로 다르면
		return true;
	else
		return false;
	
}

void move(int count, int obj) {

	if (onlyonedrop()) {
		cout << obj << "\n";
		exit(1);
	}

	if (p[0].first == p[1].first && p[0].second == p[0].first) {
		cout << -1 << "\n";
		exit(2);
	}

	if (count == obj) {
		return;
	}

	
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 2; k++) {
			int sr = p[k].first + dr[i];
			int sc = p[k].second + dc[i];
			
			if (0 <= sr && sr < N && 0 <= sc && sc < M)
			{
				if (map[sr][sc] != '#')
					continue;
			}
			cout << "hi0\n";
			cout << "p[" << k << "].first/second" << p[k].first << "/" << p[k].second;
			map[p[k].first][p[k].second] = '.';
			cout << "hi1\n";
			p[k].first = sr;
			p[k].second = sc;
			if (0 <= sr && sr < N && 0 <= sc && sc < M) {
				map[p[k].first][p[k].second] = 'o';
			}
			else

			cout << "hi2\n";
		}

		

		move(count + 1, obj);

		for (int k = 0; k < 2; k++) {
			cout << "hi3\n";
			map[p[k].first][p[k].second] = '.';
			cout << "hi4\n";
			p[k].first = p[k].first - dr[i];
			p[k].second = p[k].second - dc[i];
			if (0 <= p[k].first && p[k].first < N && 0 <= p[k].second && p[k].second < M) {
				map[p[k].first][p[k].second] = 'o';
			}
			cout << "hi5\n";
		}
	}

	


}

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	cin >> N;
	cin >> M;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o' && count == 0) {
				p[0] = make_pair(i, j);
				count++;
			}
			if (map[i][j] == 'o' && count == 1) {
				p[1] = make_pair(i, j);
			}
		}
	}

	for (int i = 1; i <= 10; i++) {
		cout << "move" << i << '\n';
		move(0,i);
	}
	cout << -1<<"\n";

	//printmap();
	//cout << "success\n";
	return 0;
}