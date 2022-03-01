#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int num;
	cin >> num;
	vector<int> v(num, 0);

	for (int i =0;i<v.size();i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	/*for (int i : v)
		cout << i;*/

	int ans = 0;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		ans += sum;
	}
	cout << ans;


}