#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int solution(vector<vector<int>> items, vector<vector<int>> coupons) {
	int answer = 0;
	sort(items.begin(), items.end());
	sort(coupons.begin(), coupons.end());
	
	while (true) {
		if (items.empty())
			break;
		if (coupons.empty()) {
			answer += items.back()[0];
			items.back()[1]--;
			if (items.back()[1] <= 0) {
				items.pop_back();
			}
			continue;
		}

		int price= items.back()[0];
		int dis_rate = coupons.back()[0];
		answer += price * (100 - dis_rate) / 100;
		items.back()[1]--;
		if (items.back()[1] <= 0) {
			items.pop_back();
		}
		coupons.back()[1]--;
		if (coupons.back()[1] <= 0) {
			coupons.pop_back();
		}

	}


	return answer;
}
int main(void) {
	vector<vector<int>> items = { {25400,2}, {10000,1}, {31600,1} };
	vector<vector<int>> coupons = { {5,3}, {23,2}, {11,2} , {9,5} };

	cout << solution(items, coupons);
}