#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;
vector<pair<long long int, long long int>> p;
vector<vector<long long int>> a_m(4, vector<long long int>(4)); // ���� ���.

long long int pdis(int i, int j) {
	return (long long int)(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));
}

bool square_check() {
	int a = 0;// index 0 point
	int b; // 

	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a_m[i][j] = pdis(i, j);
		}
	}
	// power distance �� ������ ������ ���̺� ä���.

	int opp  = -1; // opposite
	auto max_v = numeric_limits<long long int>::min();
	for (int i = 1; i <= 3; i++) {
		if (max_v <  a_m[0][i]) {
			max_v = a_m[0][i];
			opp = i;
		}
	}
	//�ݴ��� ã��.
	

	long long int pline = 0; //  ���� ����. power line.
	for (int i = 1; i <= 3; i++) {
		if (i!= opp) {
			pline = a_m[0][i];
			break;
		}
	}
	// ������ �Ǵ� ���� ����  ã��.


	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			//�Ʒ� ������ �밢���� �����ϱ� ���� ����.
			// i�� j�� 0�� opp �̸� �ȵǰ�, �׷����� �����̶� 0�̳� opp�� �����ؾ��Ѵ�.
			//ex) 0�� 3�� �ݴ������ ���̸� 1�� 2�� �ݴ����.
			
			if (!((i == 0 || i == opp )&&( j == 0 ||  j== opp)) && (i == 0 || i == opp || j == 0 || j == opp)) {
				if (pline != a_m[i][j])
					return false;
			}
		}
	}
	// ��� ���� ���� ���� ����.


	for (int i = 1; i <= 3; i++) {
		if (i != opp) {
			if (a_m[0][opp] == a_m[0][i] + a_m[i][opp]) { // a^2 + b^2 = c^2  ��Ÿ���
				return true;
			}
			else
				return false;
		}
	}	// �밢�� �ϳ��� ��Ÿ��󽺸� �����ϴ°�


	return true;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;//test case number
	cin >> t;
	for (int i = 0; i < t; i++) {
		p.clear();
		for (int j = 0; j < 4; j++) {
			long long int x;
			long long int y;
			cin >> x;
			cin >> y;
			p.push_back(make_pair(x, y));
		}
		if (square_check())
			cout << "1\n";
		else
			cout << "0\n";
	}
}