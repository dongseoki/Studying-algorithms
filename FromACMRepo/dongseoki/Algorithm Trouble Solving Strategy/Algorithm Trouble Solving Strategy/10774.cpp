#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int cti(char ch) { // char to int
	switch (ch) {
		case 'L' :
			return 3;
		case 'M':
			return 2;
		case 'S':
			return 1;
		case 'X':
			return -1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능

	vector<char> js;
	int J;
	int A;
	int ans =0;
	//scanf("%d", &J);
	//scanf("%d", &A);
	cin >> J;
	cin >> A;
	js.push_back('0'); // 의미 없는 값. this vector start from 1 not 0.
	for (int i = 0; i < J; i++) {
		char ch;
		cin >> ch;
		js.push_back(ch);
	}
	for (int i = 0; i < A; i++) {
		char ch;
		int num;
		cin >> ch;
		cin >> num;
		//scanf("%c %d", &ch, &num);
		if (cti(ch) <= cti(js[num])) {
			js[num] = 'X';
			ans++;
		}
	}

	printf("%d", ans);
}