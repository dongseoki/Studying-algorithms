#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

long long int blackchain(long long int n) {
	long long int x = 0;
	while (1) {

		long long int result = (x + 1) * pow(2, (x+1))-1;
		//cout << result << "\n";
		if (n <= result)
			return x;
		x = x + 1;
	}
	
}

int main(void) {
	long long int n;
	cin >> n;
	
	if (n % 2 == 0) {
		cout << blackchain(n) + 1;
	}
	else
		cout << blackchain(n);
}