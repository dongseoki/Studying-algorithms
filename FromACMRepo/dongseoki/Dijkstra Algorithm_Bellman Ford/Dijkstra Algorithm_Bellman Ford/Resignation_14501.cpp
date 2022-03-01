//https://www.acmicpc.net/source/share/3951f443eeb8428e8176e55c9a6a7fd8
//최백준 선생님 코드

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

int counseling(int date, int sum, int N, vector<pair<int, int>> &counsel_schedule) {
	if (date == N + 1) {
		return sum;
	}
	if (date > N + 1) {
		return -210000;
	}
	int data1;
	int data2 = counseling(date + 1, sum, N, counsel_schedule);
	if (date + counsel_schedule[date].first <= N + 1) {
		data1 = counseling(date + counsel_schedule[date].first, sum + counsel_schedule[date].second, N, counsel_schedule);
		if (data1 >= data2)
			return data1;
		else
			return data2;
	}
	else
		return data2;
}

int main(void) {

	int N;
	vector<pair<int, int>> counsel_schedule;

	cin >> N;
	int date;
	int value;
	counsel_schedule.push_back(make_pair(0, 0)); // index 0 무시.
	for (int i = 0; i < N; i++) {
		cin >> date;
		cin >> value;
		counsel_schedule.push_back(make_pair(date, value));
	}

	int result = counseling(1, 0, N, counsel_schedule);
	cout << result;
}