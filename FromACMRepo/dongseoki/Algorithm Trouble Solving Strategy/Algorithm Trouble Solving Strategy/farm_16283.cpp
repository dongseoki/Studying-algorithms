#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int a, b, n, w;
	cin >> a;
	cin >> b;
	cin >> n;
	cin >> w;

	if (a == b) {
		if (n == 2 && w == 2*a) {
			cout << "1 1\n";
			return 0;
		}
		else {
			cout << "-1\n";
			return 0;
		}
	}
	
	int x = (w - b * n) / (a - b);
	int r = (w - b * n) % (a - b);
	if (r != 0) {
		cout << "-1\n";
		return 0;
	}

	int y = n - x;

	if (!(x >= 1 && y >= 1)) {
		cout << "-1\n";
		return 0;
	}
	else {
		cout << x << " " << y << "\n";
		return 0;
	}
	
}

//https://msjonas.myds.me/wordpress/tag/%EB%B0%B1%EC%A4%80-16283%EB%B2%88/

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int sheepNum; // 양의 수
//	int gottNum; // 염소의 수
//	int a; // 양 한 마리가 먹는 사료의 양
//	int b; // 염소 한 마리가 먹는 사료의 양
//	int n; // 양과 염소의 총 수
//	int w; // 양과 염소가 하루 동안 소비한 전체 사료의 양
//	int solutionNum = 0; // 해의 수
//
//	cin >> a >> b >> n >> w;
//
//	for (int sN = 1, gN = n - 1; sN <= n - 1; sN++, gN--) // sN = loop에서 사용할 양의 수, gN = loop에서 사용할 염소의 수
//	{ // 양 1마리, 염소 n-1마리 부터 시작
//		if (solutionNum < 2) // 해가 2개 이상인 경우 구하는 의미가 없기 때문에 loop를 빠져나오기 위함
//		{
//			if ((sN * a + gN * b) == w) // 양들이 먹은 사료의 양 + 염소들이 먹은 사료의 양 == 하루 동안 소비한 전체 사료의 양
//			{
//				sheepNum = sN;
//				gottNum = gN;
//				solutionNum++; // 해의 수 증가
//			}
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	if (solutionNum == 1) // 유일해가 존재할 때
//	{
//		cout << sheepNum << " " << gottNum << endl;
//	}
//	else // 해가 없거나, 2개 이상일 때
//	{
//		cout << -1 << endl;
//	}
//
//	return 0;
//}