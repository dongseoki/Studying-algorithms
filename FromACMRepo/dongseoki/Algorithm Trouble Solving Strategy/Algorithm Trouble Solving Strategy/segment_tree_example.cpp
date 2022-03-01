#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999
using namespace std;
struct RMQ {
	int size;
	vector<int> minValues;

	RMQ(int* arr, int arrSize) {
		size = arrSize;
		minValues.resize(size * 4);
		init(arr, 0, size - 1, 1);
	}

	int init(int* arr, int left, int right, int node) {
		if (left == right) return minValues[node] = arr[left];

		int mid = (left + right) / 2;
		int leftMinValue = init(arr, left, mid, node * 2);
		int rightMinValue = init(arr, mid + 1, right, node * 2 + 1);

		return minValues[node] = min(leftMinValue, rightMinValue);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return INF;
		if (left <= nodeLeft && nodeRight <= right)
			return minValues[node];

		int mid = (nodeLeft + nodeRight) / 2;
		int leftMinValue = query(left, right, node * 2, nodeLeft, mid);
		int rightMinValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);

		return min(leftMinValue, rightMinValue);
	}

	int query(int left, int right) {
		return query(left, right, 1, 0, size - 1);
	}

	int update(int index, int value, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index) return minValues[node];

		if (nodeLeft == nodeRight) return minValues[node] = value;
		int mid = (nodeLeft + nodeRight) / 2;
		int leftMinValue = update(index, value, node * 2, nodeLeft, mid);
		int rightMinValue = update(index, value, node * 2 + 1, mid + 1, nodeRight);
		return minValues[node] = min(leftMinValue, rightMinValue);
	}

	int update(int index, int value) {
		return update(index, value, 1, 0, size - 1);
	}
};

int main() {

	int arr[] = { 7, 4, 5, 1, 9, 5, 2, 11, 10 };
	RMQ rmq(arr, sizeof(arr) / sizeof(int));

	printf("query(0-8) : %d\n", rmq.query(0, 8));
	printf("query(1-6) : %d\n", rmq.query(1, 6));
	printf("query(7-8) : %d\n", rmq.query(7, 8));
	printf("query(3-7) : %d\n", rmq.query(3, 7));
	printf("query(0-2) : %d\n", rmq.query(0, 2));
	printf("query(0-2) : %d\n", rmq.query(4, 8));
	printf("update(index 4, value 0)) : %d\n", rmq.update(4, 0));

}