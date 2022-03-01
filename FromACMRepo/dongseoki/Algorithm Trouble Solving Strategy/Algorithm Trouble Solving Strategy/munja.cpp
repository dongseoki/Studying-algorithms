#include <iostream>
using namespace std;
int main(void) {
	long long int n;
	cin >> n;
	int ans;
	int remain = (n - 1) % 8;
	if (remain > 4)
		remain = 8 - remain;

	ans = remain + 1;

	cout << remain<<"\n";
}