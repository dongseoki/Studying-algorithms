#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//������ �ǿ����ڷ� 'std::string' ������ ����ϴ� �����ڰ� ���ų� ���Ǵ� ��ȯ�� �����ϴ�.
// �� ���� �ذ��� #incldue <string>
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