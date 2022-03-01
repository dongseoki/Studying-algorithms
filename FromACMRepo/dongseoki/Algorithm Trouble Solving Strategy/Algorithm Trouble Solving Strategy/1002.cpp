#include <iostream>
#include <math.h>

using namespace std;

int x1, y_1, r1;
int x2, y2, r2;

int find_ru(void) {
	//두점 좌표가 같은가 ? ---------같다--------- 구한 거리가 같은가? -----------같다----------그 크기가 0인가?------------0이다 -- '1'
	//																											-----------0아니다 --'-1'
	// 이런식.
	if (x1 == x2 && y_1 == y2) {
		if (r1 == r2) {
			if (r1 == 0)
				return 1;
			else
				return -1;
		}
		else
			return 0;
	}
	else {
		double dispow = (pow(x1 - x2, 2) + pow(y_1 - y2, 2));
		double r1plusr2pow = pow(r1+r2, 2);
		if(dispow == r1plusr2pow ||(dispow == pow(r1-r2,2)))
			return 1;
		else if (dispow < r1plusr2pow)
			return 2;
		else 
			return 0;
		
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0; //test case;

	cin >> t;
	for (int i = 0; i < t; i++) {
		
		cin >> x1;
		cin >> y_1;
		cin >> r1;

		cin >> x2;
		cin >> y2;
		cin >> r2;

		cout<< find_ru()<<"\n";
	}
}