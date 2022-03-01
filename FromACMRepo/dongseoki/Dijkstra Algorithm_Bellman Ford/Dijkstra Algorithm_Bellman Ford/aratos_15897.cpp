//https://blog.naver.com/PostView.nhn?blogId=pasdfq&logNo=221319699850
// 위 사이트 참고.

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int k =0;


void test(void) {
	int n;
	cin >> n;
	int* sieve = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j += i) {
			sieve[j] += 1;
			cout << i << " " << j << "\n";
			k++;
		}
	}

	cout << "count:" << k << "\n";
}

int result(int n) {
	int sum;

	sum = 0;
	int num = n - 1;
	for (int i = 1; i <= n; i++) {
		sum += num/i +1;
		//cout <<"i : "<<i<<" (num/i +1) :  "<<(num/i + 1) <<"\n";
	}
	return sum;
}

long long solve(long long N) {
	long long sum = 0;
	long long step = 0;
	for (long long i = 1; i <= N; i += step) {
		int divided = (N - 1) / i;
		int rem = (N - 1) % i;
		step = (divided == 0 ? 1 : rem / divided + 1);
		sum += (1 + (N - 1) / i) * step;

		//cout << "(1 + (N - 1) / i): " << (1 + (N - 1) / i) <<" rem : divided "<<rem<<" | "<<divided <<" step: " << step << "\n";
	}
	return sum;
}

int main(void) {
	int n;

	//test();

	cin >> n;
	//result(n);
	cout << solve(n);
	

			
}