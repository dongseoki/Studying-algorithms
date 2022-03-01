#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;
int n;
int main(void) {
	ios::sync_with_stdio(false); //  printf 와 scanf 를 못사용하게 하면서 속도 향상을 시킴. 동기화를 해제한다.?
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	cin >> n;
	if (n <= 2) {
		cout << 1;
		return 0 ; // 이거 빼먹어서 계속 안된거임..
	}
		

	pair<long long int, long long int> bp; // before pair.
	bp.first = 1;// 0으로 끝나는거
	bp.second = 0; // 1로 끝나는 거
	pair<long long, long long int> tp; // temporary pair.
	for (int i = 3; i <= n;i++) {
		tp.first = bp.first + bp.second;
		tp.second = bp.first;
		bp.first = tp.first;// 0으로 끝나는거
		bp.second = tp.second; // 1로 끝나는 거
		//cout << i<<" " <<"z/o= "<<bp.first<<" + "<<bp.second<<"= "<< bp.first + bp.second<<"\n";
	}

	cout << bp.first + bp.second;
	return 0 ;
}