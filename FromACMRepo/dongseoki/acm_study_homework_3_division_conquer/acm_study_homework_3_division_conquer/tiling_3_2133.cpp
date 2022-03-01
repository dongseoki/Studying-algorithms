#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//오른쪽 피연산자로 'std::string' 형식을 사용하는 연산자가 없거나 허용되는 변환이 없습니다.
// 위 오류 해결방법 #incldue <string>
using namespace std;

int f(int n);
int h(int n);

int main(void) {
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}

int f(int n) {

	if (n % 2 == 1)
		return 0;
	if (n == 2)
		return 3;
	return 2 * h(n) + f(n - 2);
}

int h(int n) {
	if (n == 2)
		return 1;
	return f(n - 2) + h(n - 2);
}