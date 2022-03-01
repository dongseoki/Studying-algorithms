
//https://twpower.github.io/76-how-to-use-queue-in-cpp


#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N; //N개의 쓰레기.
int M; //M개의 소각로 칸
int K; // 종류 K개.
int Q; // 명령어의 개수.



vector<int> sogac;
queue<pair<int,int>> wait;
int waits;
queue<int> save;


void sogac_jacup(void) {
	//이렇게 한 번 태우고 나면 L번 칸부터 R번 칸까지는 비게 되는데, 
	//그때 대기열의 앞에서부터 순서대로 쓰레기를 가져와 L번 칸부터 R번 칸까지 채운다. 
	//쓰레기를 가져와 채우다가 더 이상 대기열 상에 쓰레기가 남지 않았으면 그 뒤로는 아무것도 놓지 않는다.
	int L, R; // 소각 위치.
	cin >> L;
	cin >> R;
	// 태우기
	for (int i = L; i <= R; i++)
		sogac[i] = 0;
	int qsize = waits;

	// 쓰레기 가져와 채우기. 
	//cout << "R-L+1 : qsize =" << R - L + 1 << " : " << qsize << "\n";
	int min_num = min((R - L + 1), qsize);
	for (int i = L; i < L + min_num; i++) {
		sogac[i] = wait.front().first;
		wait.front().second--;
		waits--;
		if(wait.front().second==0)
			wait.pop();
	}

}
void print_waste(void) {
	int i = 1;
	cin >> i;
	//cout << sogac[i] << " ";
	save.push(sogac[i]);
}

void print_sogac(void) {
	for (int i = 1; i <= M; i++)
		cout << sogac[i] << " ";
}

void insert(void) {
	int p, q; // p번 종류의 쓰레기 q개를 현재 대기열 뒤에 넣는다.
	//p번 종류의 쓰레기 q개를 현재 대기열 뒤에 넣는다.
	cin >> p;
	cin >> q;
	wait.push(make_pair(p, q));
	waits += q;
}
void recycle(void) {
	int t; // 재활용을 위해 현재 대기열 맨 앞의 쓰레기 t개를 제거한다.
	cin >> t;
	//재활용을 위해 현재 대기열 맨 앞의 쓰레기 t개를 제거한다.
	int qsize = waits;
	int k = min(t, qsize);
	while (k > 0) {
		if (wait.front().second > k) {
			wait.front().second -= k;
			waits -= k;
			return;
		}
		if (wait.front().second == k) {
			waits -= k;
			wait.pop();
			return;
		}
		if (wait.front().second < k) {
			waits -= wait.front().second;
			k -= wait.front().second;
			wait.pop();
		}
	}
	for (int i = 0; i < min(t, qsize);) {
		
		if (wait.front().second < t) {
			i = wait.front().second;
			waits -= wait.front().second;

		}
	}
		

}

//void print_wait(void) {
//	int qsize = wait.size();
//	int num;
//	if (qsize > 20)
//		return;
//	for (int i = 0; i < qsize; i++) {
//		num = wait.front();
//		cout << num << " ";
//		wait.pop();
//		wait.push(num);
//	}
//}
//
//void print_state(void) {
//	cout << "-----------------\n";
//	cout << "sogac\n";
//	print_sogac();
//	cout << "\nwait\n";
//	print_wait();
//	cout << "\n-----------------\n";
//
//
//}

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능

	cin >> N;
	cin >> M;
	cin >> K;
	cin >> Q;
	int cnum; // 명령어 번호.

	sogac.assign(M + 1, 0); // index 1부터 사용! 
	//소각로는 M개의 칸이 일렬로 나열되어있는 구조



	int ai;
	for (int i = 0; i < N; i++) {
		cin >> ai;
		wait.push(make_pair(ai,1));
		waits++;
	}

	//맨 처음에는 대기열의 앞에서부터 순서대로 min(N, M)개의 쓰레기를 가져와 소각로의 1번 칸부터 min(N, M)번 칸까지 순서대로 놓아둔다.
	for (int i = 1; i <= min(N, M); i++) {

		sogac[i] = wait.front().first;
		wait.pop();
		waits--;
	}



	for (int i = 0; i < Q; i++) {
		cin >> cnum;
		switch (cnum) {
		case 1:
			sogac_jacup();
			break;
		case 2:
			print_waste();
			break;
		case 3:
			insert();
			break;
		case 4:
			recycle();
			break;
		}
		//print_state();
	}

	int ssize = save.size();
	for (int i = 0; i < ssize; i++) {
		cout << save.front() << " ";
		save.pop();
	}
	cout << "\n";
	print_sogac();
	return 0;
}