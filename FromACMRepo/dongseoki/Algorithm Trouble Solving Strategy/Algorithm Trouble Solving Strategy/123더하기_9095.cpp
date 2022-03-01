#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;
int n;
int sum_123(int n);
int cache[1001];


int main(void) {
	ios::sync_with_stdio(false); //  printf 와 scanf 를 못사용하게 하면서 속도 향상을 시킴. 동기화를 해제한다.?
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << sum_123(n)<<"\n";
	}
	
	return 0;
}

int sum_123(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	int& ref = cache[n];
	if (ref != -1) {
		return ref;
	}

	ref = sum_123(n - 1) + sum_123(n - 2) + sum_123(n - 3);

	return ref;
}