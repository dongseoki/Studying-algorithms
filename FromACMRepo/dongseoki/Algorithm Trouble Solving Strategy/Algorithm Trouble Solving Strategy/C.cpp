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
				//cout << i - 1<<"���"<<"\n";
				//buy(i - 1,d_v);
				// v1 �������� ���� ���.

				int max = v2;
				v1 = v2;
				for (int j = i; j < n; j++) {
					v2 = d_v[j];
					if (v1 > v2) {
						//cout << j - 1<<"�ȱ�" << "\n";// test
						buy(i - 1, d_v);
						//print_v();
						sell(j - 1, d_v);
						//print_v();
						//  ���� �ȱ�.
						i = j-1; // �ű⼭ ���� �ٽ� ����.
						break;

					}
					else { // v1 <=v2 // ��¼�.
						// ������ ���� ó���ؾ� �ҵ�.
						v1 = v2;
						if (j == n - 1) {
							//cout << j << "�ȱ�\n";
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