#include <iostream>
#include <vector>
#include <string>
#define F(p,q,r) for(int p = q; p<r;p++)
using namespace std;


int main(void) {
	int N = 0;

	cin >> N;
	vector <int> tree_height_vec(N, 0);

	F(idx, 0, N) {
		cin >> tree_height_vec[idx];
	}

	//cout << "\n-----test--------\n";
	//F(idx, 0, N) {
	//	cout << tree_height_vec[idx]<<" ";
	//}
	int realOddCount = 0;
	int availTwoCount = 0;
	int sum = 0;
	for (auto item : tree_height_vec) {
		if (item % 2 == 1) {
			realOddCount++;
		}
		availTwoCount += item / 2;
		sum += item;
	}

	if (sum % 3 != 0) {
		cout << "NO";
	}
	else  {
		if (realOddCount <= availTwoCount)
			cout << "YES";
		else
			cout << "NO";
	}
}