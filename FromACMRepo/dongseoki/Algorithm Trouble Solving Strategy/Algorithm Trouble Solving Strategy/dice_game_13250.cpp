#include <iostream>
#include <vector>

using namespace std;
vector<double> hope(1000001, 0);
int main(void) {
	int N;
	cin >> N;
	hope[1] = 1;
	
	for (int i = 2; i <= N; i++) {
		double hope_v =0; // hope value.
		if (i <= 7) {
			for (int j = 1; j < i; j++) {
				hope_v += hope[j];
			}
		}
		else {
			for (int j = 1; j <= 6; j++) {
				hope_v += hope[i-j];
			}
		}
				hope[i] = hope_v / 6 +1;
	}
	printf("%.10f", hope[N]);
//	[출처] [알고리즘] 백준 주사위게임 | 작성자 코랑이


	//cout << hope[N]<<"\n";
}