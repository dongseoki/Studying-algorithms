//http://blog.naver.com/PostView.nhn?blogId=njw1204&logNo=221459439369&categoryNo=76&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int N;
vector<int> A, B;

int Solve1() {
	int bitcnt[30] = {}, bitsum[30] = {};

	for (int i : A) {
		for (int j = 0; j < 30; j++) {
			int base = 1 << j;
			if (i & base)
				bitcnt[j]++;
		}
	}

	cout << "\n--------------bitcnt 결과 --------\n";
	for (int j = 0; j < 30; j++) {
		cout << bitcnt[j]<<" ";
	}


	for (int i : B) {
		for (int j = 0; j < 30; j++) {
			int base = 1 << j;
			if (i & base)
				bitsum[j] = (bitsum[j] + bitcnt[j]) % 1999;
		}
		cout << "\n--------------bitsum 결과 --------\n";

		for (int j = 0; j < 30; j++) {
			cout << bitsum[j] << " ";
		}
		cout << "\n";
	}
	

	int ans = 0;
	for (int i = 0; i < 30; i++) {
		ans += (1 << i) % 1999 * bitsum[i] % 1999;
		ans %= 1999;
	}
	return ans;
}

int Solve2() {
	int minA[30][2] = {}, minB[30][2] = {};
	int maxA[30][2] = {}, maxB[30][2] = {};
	const char* _m = "minA[i][j] : 수열 A에서, 하위 i+1개의 비트만 봤을때 최상위 비트가 j인 수들 중에 최솟값";

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 2; j++) {
			minA[i][j] = INT_MAX;
			maxA[i][j] = INT_MIN;
			minB[i][j] = INT_MAX;
			maxB[i][j] = INT_MIN;
		}
	}

	int mask = 1, firstBit = 1;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < N; j++) {
			int aFirst = 0, bFirst = 0;
			if (A[j] & firstBit) aFirst = 1;
			if (B[j] & firstBit) bFirst = 1;

			minA[i][aFirst] = min(minA[i][aFirst], A[j] & mask);
			maxA[i][aFirst] = max(maxA[i][aFirst], A[j] & mask);
			minB[i][bFirst] = min(minB[i][bFirst], B[j] & mask);
			maxB[i][bFirst] = max(maxB[i][bFirst], B[j] & mask);
		}

		mask = (mask << 1) + 1;
		firstBit <<= 1;
	}

	char result[30] = {};
	memset(result, 1, sizeof(result));
	firstBit = 1;

	for (int i = 0; i < 30; i++) {
		if (minA[i][0] != INT_MAX && minB[i][0] != INT_MAX &&
			((minA[i][0] + minB[i][0]) & firstBit) == 0)
			result[i] = 0;

		if (maxA[i][1] != INT_MIN && maxB[i][0] != INT_MIN &&
			((maxA[i][1] + maxB[i][0]) & firstBit) == 0)
			result[i] = 0;

		if (maxA[i][0] != INT_MIN && maxB[i][1] != INT_MIN &&
			((maxA[i][0] + maxB[i][1]) & firstBit) == 0)
			result[i] = 0;

		if (minA[i][1] != INT_MAX && minB[i][1] != INT_MAX &&
			((minA[i][1] + minB[i][1]) & firstBit) == 0)
			result[i] = 0;

		firstBit <<= 1;
	}

	int ans = 0, weight = 1;
	for (int i = 0; i < 30; i++) {
		if (result[i]) ans += weight;
		weight <<= 1;
	}
	return ans;
}

void test(void) {
	int sum = 0;
	for (int i : A) {
		for (int j : B) {
			sum += i & j;
		}
	}
	cout << "\ntest 결과\n";
	cout << sum << "\n";

	int result;
	for (int i : A) {
		for (int j : B) {
			sum += i & j;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		B.push_back(x);
	}

	cout << Solve1() << ' ' << Solve2();
	test();
	return 0;
}
//[출처] 백준 15896번 & ++&| 작성자 njw1204