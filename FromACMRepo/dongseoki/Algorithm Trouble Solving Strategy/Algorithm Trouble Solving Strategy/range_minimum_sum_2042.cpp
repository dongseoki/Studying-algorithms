//https://www.acmicpc.net/blog/view/21
//
//https://greeksharifa.github.io/algorithm%20&%20data%20structure/2018/07/09/algorithm-fenwick-tree/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct RMQ {
	//range maxium queue ���� �ִ� Ʈ��.
	int size;
	// size = ������ ũ��.
	vector<long long> r_s_v; // range sum values..
	RMQ(const vector<long long>& numvec, int vecSize) {
		size = vecSize;
		r_s_v.resize(4 * size);
		init(numvec, 0, size - 1, 1);
	}
	
	void show() {
		cout << "\n";
		for (int i : r_s_v) {
			cout << i << " ";
		}

		cout << "\n";
	}

	long long init(const vector<long long>& numvec, int left, int right, int node) {
		if (left == right)
			return r_s_v[node] = numvec[left];
		int mid = (left + right) / 2;
		long long leftSumValue = init(numvec, left, mid, node * 2);
		long long rightSumValue = init(numvec, mid + 1, right, node * 2 + 1);

		return r_s_v[node] = leftSumValue + rightSumValue;
	}

	// �������� ��ȯ�Ѵ�.
	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
		//1. �������� ������.
		if (right <nodeLeft || left> nodeRight)
			return 0;
		//2. Ž�� ������ ǥ�� ������ ���� �����Ҷ�
		if (left <= nodeLeft && nodeRight <= right){
			return r_s_v[node];
		}

		// �׿�.
		int mid = (nodeLeft + nodeRight) / 2;
		long leftSumValue = query(left, right, node * 2, nodeLeft, mid);
		long rightSumValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);

		return leftSumValue + rightSumValue;
	}
	
	long long query(int left, int right) {
		return query(left, right, 1, 0, size - 1);
	}

	// ���� Ʈ���� �����ϰ� ��尡 ǥ���ϴ� ������ �������� ��ȯ�Ѵ�.
	long long update(int index, int value, int node, int nodeLeft, int nodeRight) {
		if (index <nodeLeft || nodeRight < index)
			return r_s_v[node];

		if (nodeLeft == nodeRight)
			return r_s_v[node] = value;

		int mid = (nodeLeft + nodeRight) / 2;
		long long leftSumValue = update(index, value, node * 2, nodeLeft, mid);
		long long rightSumValue = update(index, value, node * 2 + 1, mid + 1, nodeRight);
		return r_s_v[node] = leftSumValue + rightSumValue;
	}

	long long update(int index, int value) {
		return update(index, value, 1, 0, size - 1);
	}

};

int main(void) {
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����

	
	int N;
	int M;
	int K;
	cin >> N;
	cin >> M;
	cin >> K;
	vector<long long> numvec(N);

	for (int i = 0; i < N; i++) {
		cin >> numvec[i];
	}
	/*cout << numvec.size()<<"\n";
	cout << sizeof(numvec) / sizeof(int);*/

	RMQ rmq(numvec, numvec.size());
	//rmq.show();
	for (int i = 0; i < M+K; i++) {
		int a;
		int b;
		int c;
		cin >> a;
		cin >> b;
		cin >> c;
		if (a == 1) {
			rmq.update(b - 1, c);
			//numvec[b - 1] = c;
		}
		else if (a == 2) {
			cout << rmq.query(b - 1, c - 1) << "\n";
		}
	}


}