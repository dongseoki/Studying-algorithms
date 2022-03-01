#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int make_one(int n);

int cache[1000001];
//int chae[];
int n;
int main(void) {
	//vector<int> cache;
	//memset(cache, 0, )
	
	ios::sync_with_stdio(false); //  printf 와 scanf 를 못사용하게 하면서 속도 향상을 시킴. 동기화를 해제한다.?
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	cin>>n;

	memset(cache, -1, sizeof(cache));
	if(n==1)
		cout << 0;
	else
		cout << make_one(n);
}

int make_one(int n) {
	if (n <= 3)
		return 1;

	int& ref = cache[n];

	if (ref != -1)
		return ref;

	ref = 1 + make_one(n - 1);
	if (n % 2 == 0)
		ref = min(ref, 1 + make_one(n / 2));

	if (n % 3 == 0)
		ref = min(ref, 1 + make_one(n / 3));


	return ref;
}