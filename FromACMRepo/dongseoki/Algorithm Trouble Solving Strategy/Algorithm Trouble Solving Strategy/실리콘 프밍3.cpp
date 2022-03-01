#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> estimates, int k) {
	int answer = 0;

	//1�ܰ�. �ϴ� ���ϰ� ����.
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += estimates[i];
	}
	answer = sum;

	//2�� ��. �յڷ� ����.
	int start = 1;
	int end = start + k - 1;
	int pretemp = answer;
	while (true) {
		if (end < estimates.size()) {
			int temp = pretemp- estimates[start - 1] + estimates[end];
			if (temp > answer)
				answer = temp;

			start++;
			end++;
			pretemp = temp;
		}
		else
			break;
	}


	return answer;
}

int main(void) {
	int length;
	int k;
	cin >> length;
	cin >> k;
	vector<int> estimates(length,0);
	for (int i = 0; i < estimates.size(); i++) {
		cin >> estimates[i];
	}
	int result = solution(estimates, k);
	cout << result;
}