#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Trie {
	Trie* next[10];
	bool term;
	Trie() : term(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(string s, int i) {
		if (i >= s.size()) {
			term = true;
		}
		else {
			int curr = s[i] - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(s,i+1);
		}
	}
	bool find(string s, int i) {
		if (i >= s.size()) {
			return false;
		}
		if (term)
			return true;
		// 위는 겹치는 녀석이 있다는 의미.
		int curr = s[i] - '0';
		return next[curr]->find(s, i+1);
	}
};


bool solution(vector<string> phone_book) {
	bool answer = true;
	struct Trie T;
	for (auto item : phone_book) {
		T.insert(item,0);
	}
	for (auto item : phone_book) {
		if (T.find(item, 0) == true) {
			answer = false;
		}
	}
	//phone_book
	return answer;
}

int main(void) {
	//[119, 97674223, 1195524421] false
	//	[123, 456, 789]	true
	//	[12, 123, 1235, 567, 88]	false
	cout <<solution({ "119", "97674223", "1195524421" })<<"\n";
	cout << solution({ "123", "456", "789" }) << "\n";
	cout << solution({ "12", "123", "1235", "567", "88" }) << "\n";
	//	[]	false
}