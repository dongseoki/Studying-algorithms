//https://rebas.kr/717
// �� �ڵ� �� �� Ǯ����.

#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
void selected(int start,int count);
void print_numbers(void);

void selected_v(int start, int count);
void print_numbers2(void);

int intarr[9];
vector<int> vec(9);


int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����
	cin >> N;
	cin >> M;

	//selected(1,0);
	selected_v(1, 0);
	return 0;
}

void selected(int start, int count){

	if (count == M) {
		print_numbers();
		cout << "\n";
		return;
	}

	for (int i = start; i <= N; i++) {
		if (intarr[i] == 0) {
			intarr[i] = 1;
			selected(i+1,count + 1);
			intarr[i] = 0;
		}

	}
}

void print_numbers(void) {
	for (int i = 1; i <= N; i++) {
		if (intarr[i] == 1)
			cout << i << " ";
	}
}

void selected_v(int start, int count) {

	if (count == M) {
		print_numbers2();
		cout << "\n";
		return;
	}

	for (int i = start; i <= N; i++) {
		if (vec[i] == 0) {
			vec[i] = 1;
			selected_v(i + 1, count + 1);
			vec[i] = 0;
		}

	}
}
void print_numbers2(void) {
	for (int i = 1; i <= N; i++) {
		if (vec[i] == 1)
			cout << i << " ";
	}
}


