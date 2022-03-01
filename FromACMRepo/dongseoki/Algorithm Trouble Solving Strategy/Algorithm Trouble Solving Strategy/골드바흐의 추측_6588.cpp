#include <iostream>
using namespace std;

bool* Eratos(int n)
{
	/*  ���� n�� 1���� �۰ų� ������ �Լ� ���� */
	if (n <= 1) return NULL;

	/*	2���� n���� n-1���� ������ �� �ִ� �迭 �Ҵ�
		�迭 ���� ��ȣ�� �Ҽ��� ��ġ�ϵ��� �迭�� ũ���
		n+1 ���̸�ŭ �Ҵ�(�ε��� ��ȣ 0�� 1�� ������� ����)	*/
	bool* PrimeArray = new bool[n + 1];

	/*  �迭�ʱ�ȭ: ó���� ��� �Ҽ��� ���� true���� ��	*/
	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;

	/*	�����佺�׳׽��� ü�� �°� �Ҽ��� ����
		����, PrimeArray[i]�� true�̸� i ������ i ����� ����� i��
		������ �ִ� ���� �ǹǷ� i ������ i ����� ���� false���� �ش�.
		PrimeArray[i]�� false�̸� i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ����
		�Ҽ��� �ƴϰ� �ȴ�. �׷��Ƿ� �˻��� �ʿ䵵 ����.
���� i*k (k < i) ������ �̹� �˻�Ǿ����Ƿ� j���� ���� i*2 ���� i*i�� ������ �� �ִ�.
	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}
	return PrimeArray;

	// ������ �۾� ...
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bool* PrimeArray = Eratos(1000000);
	int num = 0;
	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		int flag = 0;
		for (int i = 3; i < 1000000; i++) {
			if (PrimeArray[i] == true && PrimeArray[num - i] == true) {
				cout << num << " = " << i << " + " << num - i << "\n";
				flag = 1;
				break;
			}
				/*8 = 3 + 5
				20 = 3 + 17
				42 = 5 + 37*/
		}

		if (flag == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}
