#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
bool flag;


struct Trie {
	char char_x;
	bool finish;    //끝나는 지점을 표시해줌
	Trie* next[26];    //26가지 알파벳에 대한 트라이
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
			finish = true;    //문자열이 끝나는 지점일 경우 표시
		else {
			int curr = *key - char_x;
			if (next[curr] == NULL)
				next[curr] = new Trie(char_x);    //탐색이 처음되는 지점일 경우 동적할당
			next[curr]->insert(key + 1);    //다음 문자 삽입
		}
	}
	Trie* find(const char* key) {
		if (*key == '\0')return this;//문자열이 끝나는 위치를 반환
		int curr = *key - char_x;
		if (next[curr] == NULL)return NULL;//찾는 값이 존재하지 않음
		return next[curr]->find(key + 1); //다음 문자를 탐색
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
	//	cout << "\n찾음\n";
	//}
	//else {
	//	cout << "\n못찾음\n";
	//}
	
	//if (t.find("ABC") != NULL) {
	//	cout << "\n찾음\n";
	//}
	//else {
	//	cout << "\n못찾음\n";
	//}

}

//출처: https://jason9319.tistory.com/129 [ACM-ICPC 상 탈 사람]