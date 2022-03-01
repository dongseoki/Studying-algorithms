#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

long long int N;
long long int M;
long answer[200001];
vector<long long int> graph[200001]; // ����� ���� �׷���
set<long long int> adj; // ������ ����� ã�� set
// set  ������ ����� �߿� ��� �Ѹ��� �ϰ� �ִµ�, �ڽ��� �ϰ� ���� �ʴ� ������� ��ȣ�� ����.


void input();
void solve();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();
	for (long long int i = 1; i <= N; i++) {
		cout << answer[i] << ' ';
	}
	//cout << '\n';
}

void input() {
	memset(answer, -1, sizeof(answer) / sizeof(long long int));
	cin >> N;
	long long int tmp;
	for (long long int i = 1; i <= N; i++) {
		while (true) {
			cin >> tmp;
			if (tmp != 0) 
				graph[i].push_back(tmp);
			
			else 
				break;
		}
	}

	cin >> M;

	//for (long long int i = 1; i <= M; i++) {
	//	cin >> tmp;
	//	answer[tmp] = 0;
	//	for (long long int i = 0; i < graph[tmp].size(); i++) {
	//		if (answer[graph[tmp][i]] == -1) adj.insert(graph[tmp][i]); // �����ڿ� ����� �ֺ����� �����ڰ� �ƴ϶��,  ���� �¿� �߰�.
	//	}
	//}

	vector<int> YupoList;
	for (long long int i = 0; i < M; i++) {
		cin >> tmp;
		YupoList.push_back(tmp);
		answer[tmp] = 0;
	}



	for (long long int i = 0; i < M; i++) {
		int yupoNum = YupoList[i];
		for (long long int j = 0; j < graph[yupoNum].size(); j++) {
			if (answer[graph[yupoNum][j]] == -1)
				adj.insert(graph[yupoNum][j]); // �����ڿ� ����� �ֺ����� �����ڰ� �ƴ϶��,  ���� �¿� �߰�.
		}
	}
}

void solve() {

	long long int flag = 1; // ��ȭ�� �־����� Ȯ���ϴ� �÷���, ��ȭ�� ������ 1, ������ 0
	long long int time = 1;
	while (flag == 1) {
		flag = 0;
		vector<long long int> insert_list; // adj set�� �߰��� ����Ʈ
		vector<long long int> erase_list; // adj set���� ������ ����Ʈ
		for (set<long long int>::iterator iter = adj.begin(); iter != adj.end(); iter++) { // ������ ���� ��Ӹ� �ϴ� ��� ����鿡 ���Ͽ�(�ڱⰡ ��Ӹ� �� ����)
			long long int me = *iter; // me == ����
			long long int rumor_size = graph[me].size(); // �ֺ��� ��
			long long int cnt = 0; // �ֺ��� �� �ϴ� ��� ��
			for (long long int i = 0; i < rumor_size; i++) {
				if (answer[graph[me][i]] != -1) 
					cnt++; // �������� ��Ӹ� �ϴ� ���, cnt���� ����
			}

			if (cnt * 2 >= rumor_size) { // �ֺ����� ���� �̻��� ��Ӹ� ������
				erase_list.push_back(me); // �ڽ��� ������ ���տ��� ����__����
				for (long long int i = 0; i < graph[me].size(); i++) { // �ڽ��� �ֺ��ε� ��
					if (answer[graph[me][i]] == -1) 
						insert_list.push_back(graph[me][i]); // ��Ӹ� ���� �ʴ� ����� ������ ���տ� ���� ����
				}
				flag = 1; // ��ȭ�� �־����Ƿ�, �÷��׸� 1�� �������ش�.
			}
		}


		for (long long int i = 0; i < erase_list.size(); i++) { // �̹� time�� ���� �����
			if (answer[erase_list[i]] == -1) 
				answer[erase_list[i]] = time; // �ڽ��� ���� �ð��� ���� �ð��� ������Ʈ �ϰ�,
			adj.erase(erase_list[i]);
		}


		for (long long int i = 0; i < insert_list.size(); i++) { // �̹� time�� ���� ����� �ֺ��� ��(�� �� �ϴ� ���)
			if (answer[insert_list[i]] == -1)
				adj.insert(insert_list[i]);
		}
		time++;
	}
}