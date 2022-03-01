#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
	char type;
	int r;
	int c;
	//µ¿/¼­/³²/ºÏ
	vector<Node*> next;
	Node(int r, int c, char type) : r(r), c(c), type(type), next(4, NULL) {
	}

}
;
vector<vector<Node*>> U;
vector<vector<Node*>> L;

bool compareL(Node* a, Node* b) {
	return a->c < b->c;
}
bool compareU(Node* a, Node* b) {
	return a->r < b->r;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K, Q;
	cin >> N;
	cin >> M;
	cin >> K;
	cin >> Q;
	int r;
	int c;
	char type;

	L.assign(N + 1, vector< Node* >());
	U.assign(M + 1, vector< Node* >());



	for (int i = 1; i <= N; i++) {
		L[i].push_back(new Node(i, -1, 'X'));
	}

	for (int i = 1; i <= M; i++) {
		U[i].push_back(new Node(-1, i, 'X'));
	}

	for (int i = 1; i <= N; i++) {
		L[i].push_back(new Node(i, N+1, 'X'));
	}

	for (int i = 1; i <= M; i++) {
		U[i].push_back(new Node(M+1, i, 'X'));
	}




	for (int i = 0; i < K; i++) {
		cin >> r;
		cin >> c;
		cin >> type;
		L[r].push_back(new Node(r, c, type));
		U[c].push_back(new Node(r, c, type));
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < L[i].size(); j++) {
			cout << L[i][j]->type << "(" << L[i][j]->r << "," << L[i][j]->c << ")" << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
			sort(L[i].begin(), L[i].end(), compareL);
	}

	for (int i = 1; i <= M; i++) {
		sort(U[i].begin(), U[i].end(), compareU);
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < L[i].size(); j++) {
			cout << L[i][j]->type <<"("<< L[i][j]->r <<","<< L[i][j]->c <<")"<< " ";
		}
		cout << "\n";
	}


}