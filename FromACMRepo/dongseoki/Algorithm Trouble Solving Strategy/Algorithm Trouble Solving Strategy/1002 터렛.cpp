#include <iostream>
#include <math.h>

using namespace std;

int x1, y_1, r1;
int x2, y2, r2;

int find_ru(void) {
	double distance = sqrt(pow(x1 - x2, 2) + pow(y_1 - y2, 2));
	if (abs(r1 - r2) < distance && distance < (r1 + r2)) {
		return 2;
	}
	else if (distance == (r1 + r2) || (abs(r2 - r1) == distance && distance != 0)) {
		// 외접.
		// 내접
		return 1;
	}
	else if (distance == 0 && r1 == r2) {
		return -1;
	}
	else
		return 0;
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

		cout << find_ru() << "\n";
	}
}