#include <iostream>

#include <algorithm>

using namespace std;



int main() {



	int a[10] = { 17, 25, 67, 84, 90, 30, 55, 6, 9, 28 };

	sort(a, a + 10);



	cout << "�� 55: ";

	if (binary_search(a, a + 10, 55)) cout << "ã�ҽ��ϴ�." << endl;

	else cout << "ã�� ���߽��ϴ�." << endl;



	cout << "�� 80: ";

	if (binary_search(a, a + 10, 80)) cout << "ã�ҽ��ϴ�." << endl;

	else cout << "ã�� ���߽��ϴ�." << endl;



	return 0;

}