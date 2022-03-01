#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int money = 0;
	int ans = 0;
	cin >> money;
	money = 1000 - money;
	int arr[] = { 500,100,50,10,5,1 };
	for (int i = 0; i < 6; i++) {
		//cout << "now :" << money <<" "<<ans<<" "<<arr[i] << "\n";
		ans += money / arr[i];
		money %= arr[i];
		if (money == 0)
			break;
	}
	cout << ans;
	return 0;
}