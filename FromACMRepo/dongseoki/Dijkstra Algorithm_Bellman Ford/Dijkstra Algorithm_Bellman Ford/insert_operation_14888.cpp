//https://rebas.kr/717
// 위 코드 분 잘 풀으심.

#include <iostream>
#include <vector>
using namespace std;

int N;
int M;

void selected_v(int start, int count);
void print_numbers2(void);

int intarr[9];
vector<int> vec_num(11);
vector<int> vec_op_num(5);
vector<int> vec_op;
int max_num = -1000000001;
int min_num = 1000000001;

int result;
int calculate(void) {
	int sum = vec_num[1];
	for (int i = 0; i < vec_op.size(); i++) {
		switch (vec_op[i]) {
		case 1:
			sum += vec_num[i + 2];
			break;
		case 2:
			sum -= vec_num[i + 2];
			break;
		case 3:
			sum *= vec_num[i + 2];
			break;
		case 4:
			sum /= vec_num[i + 2];
			break;
		}
	}
	return sum;
}
int result_cal;
void test(int count) {
	if (count == N - 1) {
		result++;
		result_cal = calculate();
		if (result_cal > max_num)
			max_num = result_cal;
		if (result_cal < min_num)
			min_num = result_cal;
		return;
	}

	for (int i = 1; i < vec_op_num.size(); i++) {
		if (vec_op_num[i] != 0) {
			vec_op.push_back(i);
			vec_op_num[i] = vec_op_num[i] - 1;
			test(count + 1);
			vec_op_num[i] = vec_op_num[i] + 1;
			vec_op.pop_back();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능
	cin >> N;
	int num = 0;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		vec_num[i] = num;
	}
	for (int i = 1; i <= 4; i++) {
		cin >> num;
		vec_op_num[i] = num;
	}
	//selected(1,0);
	//selected_v(1, 0);
	test(0);
	//cout << result << "\n";
	cout << max_num << "\n";
	cout << min_num;
	return 0;
}

