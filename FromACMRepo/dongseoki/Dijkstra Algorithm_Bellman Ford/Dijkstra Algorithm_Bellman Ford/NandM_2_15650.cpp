//https://rebas.kr/717
// 위 코드 분 잘 풀으심.

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
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능
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


