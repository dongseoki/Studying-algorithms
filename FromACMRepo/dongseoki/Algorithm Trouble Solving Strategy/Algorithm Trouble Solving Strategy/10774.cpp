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
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����

	vector<char> js;
	int J;
	int A;
	int ans =0;
	//scanf("%d", &J);
	//scanf("%d", &A);
	cin >> J;
	cin >> A;
	js.push_back('0'); // �ǹ� ���� ��. this vector start from 1 not 0.
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