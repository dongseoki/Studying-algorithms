#include <iostream>

using namespace std;

struct Trie {
	char char_x;
	bool finish;    //������ ������ ǥ������
	Trie* next[26];    //26���� ���ĺ��� ���� Ʈ����
	Trie(int x) : char_x(x),finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;    //���ڿ��� ������ ������ ��� ǥ��
		else {
			int curr = *key - char_x;
			if (next[curr] == NULL)
				next[curr] = new Trie(char_x);    //Ž���� ó���Ǵ� ������ ��� �����Ҵ�
			next[curr]->insert(key + 1);    //���� ���� ����
		}
	}
	Trie* find(const char* key) {
		if (*key == '\0')return this;//���ڿ��� ������ ��ġ�� ��ȯ
		int curr = *key - char_x;
		if (next[curr] == NULL)return NULL;//ã�� ���� �������� ����
		return next[curr]->find(key + 1); //���� ���ڸ� Ž��
	}
};

int main(void) {
	Trie t('A');
	t.insert("ABC");
	t.insert("ABD");
	t.insert("AC");
	if (t.find("ABS") != NULL) {
		cout << "\nã��\n";
	}
	else {
		cout << "\n��ã��\n";
	}

	if (t.find("ABC") != NULL) {
		cout << "\nã��\n";
	}
	else {
		cout << "\n��ã��\n";
	}

}

//��ó: https://jason9319.tistory.com/129 [ACM-ICPC �� Ż ���]