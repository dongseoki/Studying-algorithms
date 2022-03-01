#include <iostream>
#include <vector>
using namespace std;
int n;
long long w;
long long coin  = 0;
void buy(int day, vector<long long> &d_v) {
	int moc = w / d_v[day];
	w= w - moc * d_v[day];
	coin += moc;
}
void sell(int day, vector<long long>& d_v) {
	w += coin * d_v[day];
	coin = 0;
}
void print_v() {

	cout << "\n" << w << " " << coin << "\n";
}
int main(void) {
	
	cin >> n;
	cin >> w;
	vector<long long> d_v(n,0); // daily value of stock.
	for (int i = 0; i < n; i++) {
		cin >> d_v[i];
	}
	int min = -1;
	if (n >= 2) {
		int v1 = d_v[0];
		int v2;
		min = d_v[0];
		for (int i = 1; i < n; i++) {
			v2 = d_v[i];
			if (v1 >= v2) {
				min = d_v[i];
				v1 = v2;
			}
			else { // v1 <v2
				//cout << i - 1<<"사기"<<"\n";
				//buy(i - 1,d_v);
				// v1 시점에서 코인 사기.

				int max = v2;
				v1 = v2;
				for (int j = i; j < n; j++) {
					v2 = d_v[j];
					if (v1 > v2) {
						//cout << j - 1<<"팔기" << "\n";// test
						buy(i - 1, d_v);
						//print_v();
						sell(j - 1, d_v);
						//print_v();
						//  코인 팔기.
						i = j-1; // 거기서 부터 다시 시작.
						break;

					}
					else { // v1 <=v2 // 상승세.
						// 마지막 꺼를 처리해야 할듯.
						v1 = v2;
						if (j == n - 1) {
							//cout << j << "팔기\n";
							buy(i - 1, d_v);
							//print_v();
							sell(j, d_v);
							//print_v();
						}
					}
				}
			}
			
		}
	}
	else {
		cout << w << "\n";
		return 0;
	}
	cout << w;



	return 0;

}