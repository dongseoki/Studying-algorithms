#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	//divided value.
	//d_v.
	//quotient; q.
	//remainder. r

	// Number of runs. n_o_r
	long long int n;
	cin >> n;
	long long int d_v = 1;
	long long int n_o_r = 0;
	while (1) {
		if (d_v > n)
			break;
		if (d_v == n) {
			n_o_r += 1;
			break;
		}
		long long int q = (n - 1) / d_v;
		long long int r = (n - 1) % d_v;
		n_o_r += (q + 1) * (int(r / q) + 1);
		d_v += (int(r / q) + 1);
	}
	cout << n_o_r<<"\n";
}