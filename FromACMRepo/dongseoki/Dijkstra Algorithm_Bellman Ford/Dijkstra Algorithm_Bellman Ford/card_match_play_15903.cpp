#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<long long int> anarr;

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����
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