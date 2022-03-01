#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;

int maxcost(int N, vector<int>& p, vector<int>& mp) {
	if (N == 1) {
		return p[1];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i;j++) {
			mp[i] = max(mp[i], mp[i - j] + p[j]);
		}
	}
	return mp[N];
}


int main(void) {
	int N = 1000;
	cin >> N;
	vector<int> p(N+1, 0); // N having card pack values..
	vector<int> mp(N + 1, 0); // max profit
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	cout << maxcost(N, p, mp);
}