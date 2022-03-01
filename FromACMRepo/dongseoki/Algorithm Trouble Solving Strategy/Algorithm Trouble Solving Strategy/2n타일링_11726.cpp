#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;
int n;
int n2_tiling(int n);
int cache[1001];


int main(void) {
	ios::sync_with_stdio(false); //  printf 와 scanf 를 못사용하게 하면서 속도 향상을 시킴. 동기화를 해제한다.?
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << n2_tiling(n);
	return 0;
}

int n2_tiling(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 3;
	int sum = 0;
	vector<int> tile;// tile(1001) 이런식으로 했더니 문제가 생겼다 왜일까..
	tile.push_back(0);// index 0.. will not use.
	tile.push_back(1);
	tile.push_back(2);
	tile.push_back(3);
	for (vector<int>::size_type i = 4; i <= n; i++) {
		//cout << tile[i - 2] << " " << tile[i - 3] << "\n";
		sum = tile[i - 2] * 2 + tile[i - 3];
		sum %= 10007;
		tile.push_back(sum);
	}

	return sum;
}