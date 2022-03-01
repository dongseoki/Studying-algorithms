#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	int money = 0;
	int ans = 0;
	cin >> n;
	cin >> money;
	vector<int> coin_arr(n,0);
	for (int i = 0; i < n; i++) {
		cin >> coin_arr[i];
	}

	int big_value = 0;
	for (int i = n-1; i >= 0; i--) {
		big_value = coin_arr[i];
		ans += money / big_value;
		money = money % big_value;
		if (money == 0)
			break;
	}
	cout << ans;
}