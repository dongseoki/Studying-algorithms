#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;
int cache[1001];
int timeOfBuildingOne[1001];
vector<int> ve[1001];
// 2차원 배열 초기화 어떻게 하지?

//arr[w].empty 는 empty면 true를 반환한다.

int min_time_building(int want);

int main(void) {
	int T;
	cin >> T;
	for (int j = 0; j < T; j++) {
		memset(cache, -1, sizeof(cache));
		memset(timeOfBuildingOne, -1, sizeof(timeOfBuildingOne));
		for (int i = 0;i < 1001; i++)
			ve[i].clear();
		int N;
		cin >> N;
		int K;
		cin >> K;
		for (int i = 1; i <= N; i++)
			cin >> timeOfBuildingOne[i];

		int befor_building = 0;
		int target_building = 0;
		for (int i = 1; i <= K; i++) {
			cin >> befor_building;
			cin >> target_building;
			ve[target_building].push_back(befor_building);
		}
		int want;
		cin >> want;

		

		cout << min_time_building(want)<<"\n";
	}
	
	//cout << "hi"<<"\n";

	//for (int i = 1; i <= 4; i++)
	//	cout << cache[i] << " ";
	//cout << "\n";
}
int min_time_building(int want) {
	if (ve[want].size() == 0)
		return timeOfBuildingOne[want];

	int& ref = cache[want];
	if (ref != -1)
		return ref;

	
	int temp = -1; // -1.
	for (vector<int>::size_type i = 0; i < ve[want].size(); i++) {
		temp = max(temp, min_time_building(ve[want][i]));
	}
	ref = timeOfBuildingOne[want] + temp;
	return ref;
}
