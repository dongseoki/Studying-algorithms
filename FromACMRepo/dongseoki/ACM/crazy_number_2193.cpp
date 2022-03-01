#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;
int n;
int main(void) {
	ios::sync_with_stdio(false); //  printf �� scanf �� ������ϰ� �ϸ鼭 �ӵ� ����� ��Ŵ. ����ȭ�� �����Ѵ�.?
	cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?
	cin >> n;
	if (n <= 2) {
		cout << 1;
		return 0 ; // �̰� ���Ծ ��� �ȵȰ���..
	}
		

	pair<long long int, long long int> bp; // before pair.
	bp.first = 1;// 0���� �����°�
	bp.second = 0; // 1�� ������ ��
	pair<long long, long long int> tp; // temporary pair.
	for (int i = 3; i <= n;i++) {
		tp.first = bp.first + bp.second;
		tp.second = bp.first;
		bp.first = tp.first;// 0���� �����°�
		bp.second = tp.second; // 1�� ������ ��
		//cout << i<<" " <<"z/o= "<<bp.first<<" + "<<bp.second<<"= "<< bp.first + bp.second<<"\n";
	}

	cout << bp.first + bp.second;
	return 0 ;
}