
//https://twpower.github.io/76-how-to-use-queue-in-cpp


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N; //N���� ������.
int M; //M���� �Ұ��� ĭ
int K; // ���� K��.
int Q; // ��ɾ��� ����.



vector<int> sogac;
queue<int> wait;
queue<int> save;


void sogac_jacup(void) {
	//�̷��� �� �� �¿�� ���� L�� ĭ���� R�� ĭ������ ��� �Ǵµ�, 
	//�׶� ��⿭�� �տ������� ������� �����⸦ ������ L�� ĭ���� R�� ĭ���� ä���. 
	//�����⸦ ������ ä��ٰ� �� �̻� ��⿭ �� �����Ⱑ ���� �ʾ����� �� �ڷδ� �ƹ��͵� ���� �ʴ´�.
	int L, R; // �Ұ� ��ġ.
	cin >> L;
	cin >>R;
	// �¿��
	for (int i = L; i <= R; i++)
		sogac[i] = 0;
	int qsize = wait.size();

	// ������ ������ ä���. 
	//cout << "R-L+1 : qsize =" << R - L + 1 << " : " << qsize << "\n";
	int min_num = min((R - L + 1), qsize);
	for (int i = L; i < L+min_num; i++) {
		sogac[i] = wait.front();
		wait.pop();
	}
	
}
void print_waste(void) {
	int i =1;
	cin >> i;
	//cout << sogac[i] << " ";
	save.push(sogac[i]);
}

void print_sogac(void) {
	for (int i = 1; i <= M; i++)
		cout << sogac[i] << " ";
}

void insert(void) {
	int p, q; // p�� ������ ������ q���� ���� ��⿭ �ڿ� �ִ´�.
	//p�� ������ ������ q���� ���� ��⿭ �ڿ� �ִ´�.
	cin >> p;
	cin >> q;
	for (int i = 0; i < q; i++) {
		wait.push(p);
	}
}
void recycle(void) {
	int t; // ��Ȱ���� ���� ���� ��⿭ �� ���� ������ t���� �����Ѵ�.
	cin >> t;
	//��Ȱ���� ���� ���� ��⿭ �� ���� ������ t���� �����Ѵ�.
	int qsize = wait.size();
	for (int i = 0; i < min(t, qsize); i++)
		wait.pop();

}

void print_wait(void) {
	int qsize = wait.size();
	int num;
	if (qsize > 20)
		return;
	for (int i = 0; i < qsize; i++) {
		num = wait.front();
		cout << num << " ";
		wait.pop();
		wait.push(num);
	}
}

void print_state(void) {
	cout << "-----------------\n";
	cout << "sogac\n";
	print_sogac();
	cout << "\nwait\n";
	print_wait();
	cout << "\n-----------------\n";


}

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����

	cin >> N;
	cin >> M;
	cin >> K;
	cin >> Q;
	int cnum; // ��ɾ� ��ȣ.

	sogac.assign(M+1, 0); // index 1���� ���! 
	//�Ұ��δ� M���� ĭ�� �Ϸķ� �����Ǿ��ִ� ����



	int ai;
	for (int i = 0; i < N; i++) {
		cin >> ai;
		wait.push(ai);
	}

	//�� ó������ ��⿭�� �տ������� ������� min(N, M)���� �����⸦ ������ �Ұ����� 1�� ĭ���� min(N, M)�� ĭ���� ������� ���Ƶд�.
	for (int i = 1; i <= min(N, M); i++) {

		sogac[i] = wait.front();
		wait.pop();
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