
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;


int K;
int lnn;
vector<pair<int, int>> i_r;//inorder_result.

void m_i_i_v(int num) {
	//LVR
	if (num * 2 <= lnn) {
		m_i_i_v(num * 2);
	}
	
	i_r.push_back(make_pair(num, -1));

	if (num * 2 + 1 <= lnn) {
		m_i_i_v(num * 2 + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> K;
	lnn = (int)pow(2.0, K) -1; // last number node.
	i_r.push_back(make_pair(-1,-1));// meanless num. for index 1.
	m_i_i_v(1); //making inoder index vector.

	for (int i = 1; i <= lnn; i++) {
		int num = 0;
		cin >> num;
		i_r[i].second = num;
	}
	sort(i_r.begin(), i_r.end());

	int nln=1;// new line node.
	for (int i = 1; i <= lnn; i++) {
		cout << i_r[i].second << " ";
		if (i == nln) {
			cout << "\n";
			nln = nln * 2 + 1;
		}
	}

}
