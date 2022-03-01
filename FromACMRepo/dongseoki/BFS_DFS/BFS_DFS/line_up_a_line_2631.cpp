
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://blog.naver.com/hwasub1115/221195635827

int LIS(vector<int>& arr, int N) {
	int maxvalue = 1;
	vector<int> dp(N, 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i]=max(dp[i] , dp[j] + 1);
				//dp[i] = dp[j] + 1;
				if (maxvalue < dp[i])
					maxvalue = dp[i];
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//	cout << dp[i] << " ";
	//cout << "\n";
	return maxvalue;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int lis = LIS(arr, N);

	cout << N - lis;
}

