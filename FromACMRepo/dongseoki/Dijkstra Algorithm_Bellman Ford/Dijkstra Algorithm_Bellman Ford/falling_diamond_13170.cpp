#include <iostream>
#include <vector>
using namespace std;


int main(void) {

	int N, K, P, W;
	cin >> N;
	cin >> K;
	cin >> P;
	cin >> W;
	cout << int((P - W) / W) + N;
	return 0;

}