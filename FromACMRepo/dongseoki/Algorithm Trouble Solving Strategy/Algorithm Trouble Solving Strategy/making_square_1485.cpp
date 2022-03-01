#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;
vector<pair<long long int, long long int>> p;
vector<vector<long long int>> a_m(4, vector<long long int>(4)); // 인접 행렬.

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
	// power distance 를 값들을 가지는 테이블 채우기.

	int opp  = -1; // opposite
	auto max_v = numeric_limits<long long int>::min();
	for (int i = 1; i <= 3; i++) {
		if (max_v <  a_m[0][i]) {
			max_v = a_m[0][i];
			opp = i;
		}
	}
	//반대점 찾기.
	

	long long int pline = 0; //  제곱 선분. power line.
	for (int i = 1; i <= 3; i++) {
		if (i!= opp) {
			pline = a_m[0][i];
			break;
		}
	}
	// 기준이 되는 선분 길이  찾기.


	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			//아래 조건은 대각선을 배제하기 위한 조건.
			// i와 j가 0과 opp 이면 안되고, 그렇지만 한쪽이라도 0이나 opp를 포함해야한다.
			//ex) 0과 3이 반대방향의 점이면 1과 2도 반대방향.
			
			if (!((i == 0 || i == opp )&&( j == 0 ||  j== opp)) && (i == 0 || i == opp || j == 0 || j == opp)) {
				if (pline != a_m[i][j])
					return false;
			}
		}
	}
	// 모든 선분 길이 같나 조사.


	for (int i = 1; i <= 3; i++) {
		if (i != opp) {
			if (a_m[0][opp] == a_m[0][i] + a_m[i][opp]) { // a^2 + b^2 = c^2  피타고라스
				return true;
			}
			else
				return false;
		}
	}	// 대각선 하나가 피타고라스를 만족하는가


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