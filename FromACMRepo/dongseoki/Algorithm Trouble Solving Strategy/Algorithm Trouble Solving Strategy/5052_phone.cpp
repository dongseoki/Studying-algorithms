#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
bool flag;


struct Trie {
	char char_x;
	bool finish;    //������ ������ ǥ������
	Trie* next[26];    //26���� ���ĺ��� ���� Ʈ����
	Trie(int x) : char_x(x), finish(false) {
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
	
	int t;//test case
	int n;//Number of phone. 
	bool ans;
	vector<char*> phone_numbers;
	
	cin >> t;
	for (int i = 0; i<t; i++) {
		Trie T('0');
		cin >> n;
		phone_numbers.clear();
		//phone_numbers.resize(n);
		for (int j = 0; j < n; j++) {
			//char phone_number[11];
			char* phone_number = (char*)malloc(sizeof(char) * 11);
			scanf("%s", phone_number);
			phone_numbers.push_back(phone_number);
			T.insert(phone_number);
		}
		ans = true;
		
		for (int j = 0; j < n; j++) {
			//Trie* temp = T.find(phone_numbers[j]);
			for (int k = 0; k < 10; k++) {
				if (T.find(phone_numbers[j])->next[k] != NULL) {
					ans = false;
					break;
				}
			}
			/*if (ans == false)
				break;*/
		}
		if (ans == true) {
			cout << "YES"<<"\n";
		}
		else
			cout << "NO"<<"\n";

		
	}
	return 0;


	//t.insert("ABC");
	//t.insert("ABD");
	//t.insert("AC");
	//if (t.find("ABS") != NULL) {
	//	cout << "\nã��\n";
	//}
	//else {
	//	cout << "\n��ã��\n";
	//}
	
	//if (t.find("ABC") != NULL) {
	//	cout << "\nã��\n";
	//}
	//else {
	//	cout << "\n��ã��\n";
	//}

}

//��ó: https://jason9319.tistory.com/129 [ACM-ICPC �� Ż ���]