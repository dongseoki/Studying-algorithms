using namespace std;
#include <vector>
#include <iostream>

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<int>> piles(n, vector<int>(m, 0));
	vector<int> r_vec(n, 0); // row vector..,
	vector<int> c_vec(m, 0); // row vector..,
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> piles[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		int max = -1;
		for (int j = 0; j < m; j++) {
			int height = piles[i][j];
			if (max < height) {
				max = height;
				r_vec[i] = j;
			}
		}
	}
	// make row vector

	for (int j = 0; j < m; j++) {
		int max = -1;
		for (int i = 0; i < n; i++) {
			int height = piles[i][j];
			if (max < height) {
				max = height;
				c_vec[j] = i;
			}
		}
	}
	// make column vector

	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (r_vec[i] != j && c_vec[j] != i) {
				int height = piles[i][j];
				//cout << "test : " << height << "\n";
				sum += height;
			}
		}
	}

	cout << sum << "\n";
	return 0;
}