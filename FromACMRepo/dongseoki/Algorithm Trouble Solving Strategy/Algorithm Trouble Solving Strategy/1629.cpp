#include <iostream>
using namespace std;

long long int multi(long long int A, long long int B, long long int C) {
	if (B == 0)
		return 1;
	if (B == 1)
		return A%C;
	if (B % 2 == 0) {
		
		return (multi(A, B / 2, C) * multi(A, B / 2, C))%C;
	}
	else {
		return  ((A *(multi(A, (B-1) / 2, C))%C) * multi(A, (B-1) / 2, C)) % C;
	}
}
// bottomup
int mypower_iterative(int n, int m, int d)
{
	if (m == 1)
		return n % d;
	int n2 = n;
	int count = 1;
	int result = 1;
	while (m > 0) {
		if (m % 2 == 1){
			cout << "n2 = " << n2 << "\n";
			result = (result * n2) % d; 
			cout << "n2 는 현재 a의 m승인데 그 m은= " << count << "\n";
		}
			
		n2 = (n2 * n2) % d;
		count++;
		m /= 2;
	}
	return result;
}

int main(void) {

	long long int A;
	long long int B;
	long long int C;
	cin >> A;
	cin >> B;
	cin >> C;
	//cout << multi(A, B, C);
	cout << mypower_iterative(A, B, C);
}