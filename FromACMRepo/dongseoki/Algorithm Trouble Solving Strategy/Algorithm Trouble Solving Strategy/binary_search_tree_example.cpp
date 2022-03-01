#include <iostream>

#include <algorithm>

using namespace std;



int main() {



	int a[10] = { 17, 25, 67, 84, 90, 30, 55, 6, 9, 28 };

	sort(a, a + 10);



	cout << "값 55: ";

	if (binary_search(a, a + 10, 55)) cout << "찾았습니다." << endl;

	else cout << "찾지 못했습니다." << endl;



	cout << "값 80: ";

	if (binary_search(a, a + 10, 80)) cout << "찾았습니다." << endl;

	else cout << "찾지 못했습니다." << endl;



	return 0;

}