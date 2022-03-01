#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int i;
int j;
int k;

int same() {
	if (i == j)
		return i;
	if (i == k)
		return i;
	
	return j;
}

int check() {
	if (i == j && j == k)
		return 1;
	if (i != j && i != k && j != k)
		return 3;
	return 2;
}
int main(void) {
	vector<int> cs(4,0);
	long long int sum =0;
	long long int sangum =0;
	int s;
	int m;
	//cin >> n;
	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			for (k = 1; k <= 6; k++) {
				int ch =check();
				cs[ch] += 1;
				switch (ch) {
					case 1:
						sangum= 10000 + i * 1000;
						break;
					case 2:
						s = same();
						sangum = 1000 + s * 100;
						break;
					case 3:
						m = max(i, j);
						m = max(m, k);
						sangum = m * 100;
						break;

				}
				//cout << i << " " << j << " " << k << " "<<"case "<<ch<<" "<< sangum<<"\n";
				sum += sangum;
			}
		}
	}
	for (int i = 1; i <= 3; i++)
		cout << "case " << i << " : " << cs[i] << "\n";
	cout << (long double)sum / 216;
}