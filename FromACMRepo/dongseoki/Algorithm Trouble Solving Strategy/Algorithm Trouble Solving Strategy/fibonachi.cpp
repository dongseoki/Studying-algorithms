#include <iostream>
using namespace std;
int fibonacci(int n)
{
	int i, j;
	
	j = 0;
	i = 1;
	for (int k = 0; k < n; k++) {
		int temp = j;
		j = i;
		i = i+temp;
		//cout << "j : " << j << " i: " << i << "\n";
	}
	return j;
}
int main() {
	for (int i = 0; i < 20; i++) {
		cout << "fibonahi [" << i << "] : " << fibonacci(i) << "\n";
	}
}