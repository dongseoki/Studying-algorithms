#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;

	// 0 1 1 ����
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);

	// ����
	sort(v.begin(), v.end());

	//����
	do {
		// ���
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}

		printf("\n");

	} while (next_permutation(v.begin(), v.end()));

	return 0;

}