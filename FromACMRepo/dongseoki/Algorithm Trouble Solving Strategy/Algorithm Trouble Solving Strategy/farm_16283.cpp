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
//	int sheepNum; // ���� ��
//	int gottNum; // ������ ��
//	int a; // �� �� ������ �Դ� ����� ��
//	int b; // ���� �� ������ �Դ� ����� ��
//	int n; // ��� ������ �� ��
//	int w; // ��� ���Ұ� �Ϸ� ���� �Һ��� ��ü ����� ��
//	int solutionNum = 0; // ���� ��
//
//	cin >> a >> b >> n >> w;
//
//	for (int sN = 1, gN = n - 1; sN <= n - 1; sN++, gN--) // sN = loop���� ����� ���� ��, gN = loop���� ����� ������ ��
//	{ // �� 1����, ���� n-1���� ���� ����
//		if (solutionNum < 2) // �ذ� 2�� �̻��� ��� ���ϴ� �ǹ̰� ���� ������ loop�� ���������� ����
//		{
//			if ((sN * a + gN * b) == w) // ����� ���� ����� �� + ���ҵ��� ���� ����� �� == �Ϸ� ���� �Һ��� ��ü ����� ��
//			{
//				sheepNum = sN;
//				gottNum = gN;
//				solutionNum++; // ���� �� ����
//			}
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	if (solutionNum == 1) // �����ذ� ������ ��
//	{
//		cout << sheepNum << " " << gottNum << endl;
//	}
//	else // �ذ� ���ų�, 2�� �̻��� ��
//	{
//		cout << -1 << endl;
//	}
//
//	return 0;
//}