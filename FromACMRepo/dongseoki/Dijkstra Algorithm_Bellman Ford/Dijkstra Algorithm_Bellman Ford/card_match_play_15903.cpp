#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<long long int> anarr;

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능
	cin >> n;
	cin >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		anarr.push_back(temp);
	}

	long long int sum;
	for (int j = 0; j < m; j++) {
		std::sort(anarr.begin(), anarr.end());
		sum =anarr[0] + anarr[1];
		anarr[0] = sum;
		anarr[1] = sum;
	}
	
	sum = 0;
	for (int i = 0; i < n; i++) {

		sum += anarr[i];
		//cout << anarr[i]<<" ";
	}
	cout << sum;


	return 0;
}