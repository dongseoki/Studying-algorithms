#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.



int find_index(char ch, vector<char>& nalanh) {
	// ���̴� �׻� 8.
	for (int i = 0; i < 8; i++) {
		if (nalanh[i] == ch) {
			return i;
		}
	}
	return -1;

}

int solution(int n, vector<string> data) {
	int answer = 0;
    vector<char> nalanh = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
//	vector<char> nalanh = { 'N', 'F', 'R', 'A', 'C', 'J', 'T', 'M' };
//	vector<char> nalanh = { 'A', 'R', 'N', 'F', 'C', 'T', 'J', 'M' };
//	vector<char> nalanh = { 'A', 'R', 'C'};
	sort(nalanh.begin(), nalanh.end());

	int c = 0;
	int v_size = data.size();
	bool flag = true;
	do {
		c++; // for test.
		flag = true;
		for (int i = 0; i < v_size; i++) {
			int idx1 = find_index(data[i][0], nalanh);
			int idx2 = find_index(data[i][2], nalanh);
			int diff = abs(idx1 - idx2)-1;
			int b_f_n = data[i][4] - '0';
			switch (data[i][3]) {
			case '=':
				if (diff != b_f_n)
					flag = false;
				break;
			case '>':
				if (diff <= b_f_n)
					flag = false;
				break;
			case '<':
				if (diff >= b_f_n)
					flag = false;
				break;
			}

			if (flag == false) {
				break;
				// ȿ������ ����.
			}
		}

		if (flag == true) {
			//for (auto i : nalanh) {
			//	cout << i << " ";
			//}
			//cout << "\n";
			answer++;
		}
		//cout << '\n';
	} while (next_permutation(nalanh.begin(), nalanh.end()));
   
	//cout << c << " \n";
    return answer;
}

int main(void) {
	cout << solution(3, { "N~F=0", "R~T>2" });
}