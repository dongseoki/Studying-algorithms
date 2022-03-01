#include <string>
#include <vector>
#include <iostream>
using namespace std;
//(try_unlock(shape, i,j,m,n,key,plock)
bool try_unlock(int shape, int x, int y, int m, int n, vector<vector<vector<int>>>& karr, vector<vector<int>>& plock) {
	bool flag = true;
	if (shape == 1 && x == 3 && y == 3) {
		cout << "has to be true";
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			plock[i + x][j + y] += karr[shape][i][j];
		}
	}
	// �켱 ���Ѵ�.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (plock[i + m - 1][j + m - 1] != 1) {
				flag = false;
			}
		}
	}
	// üũ�Ѵ�.

	if (flag == true) {
		return true; // ã�� �� �� �� ���ʿ䵵 ����.
	}
	else {
		// false ��� plock �� �������.
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				plock[i + x][j + y] -= karr[shape][i][j];
			}
		}
		// ���󺹱�.

		return false;
	}

}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int m = key.size();
	//1. Ű�� ������ 4���� ����� �ϼ��Ѵ�.
	vector<vector<vector<int>>> karr(4, vector<vector<int>>(m, vector<int>(m, 0)));
	//1-0 �⺻��
	//1-1 ������ 90�� ȸ��
	//1-2 180��
	//1-3 270��.
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < m; y++) {
			karr[0][x][y] = key[x][y];
			karr[1][y][m - 1 - x] = key[x][y];
			karr[2][m - 1 - x][m - 1 - y] = key[x][y];
			karr[3][m - 1 - y][x] = key[x][y];
		}
	}

	//test..
	//for (int k = 0; k < 4; k++) {
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < m; j++) {
	//			cout << karr[k][i][j] << " ";
	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n\n";
	//}
	

	//2. �� Ű�� ���δ� �ִ´�. �� ������ �ϳ��� �����ϸ� Ʈ��
	// ��� ���и� false�� ��������.
	//2-1 �켱 zero �е� ���� ū �簢���� ������.
	int n = lock.size();
	vector<vector<int>> plock(2 * m + n - 2, vector<int>(2 * m + n - 2, 0));


	// 2-2 �� �簢���� lock ���� �Ű� ����.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			plock[i + m - 1][j + m - 1] = lock[i][j];
		}
	}
	int e_idx = m + n - 2;
	for (int i = 0; i <= e_idx; i++) {
		for (int j = 0; j <= e_idx; j++) {
			for (int shape = 0; shape < 4; shape++) {
				if (try_unlock(shape, i,j,m,n,karr,plock) == true) {
					return true;
				}
			}
		}
	}

	// ���� ���� �°��� �ϳ��� ���ٴ� ��
	return false;
}
void f(vector<int> a) {
	;
}
int main(void) {
	vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	cout << solution(key, lock);

}