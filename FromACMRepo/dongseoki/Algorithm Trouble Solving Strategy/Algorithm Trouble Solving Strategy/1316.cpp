#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<int> letters(26, 0);

int goyeah(char str[], int index, int prelettertoint) {
	int length = strlen(str);
	int lettertoint;
	for (int i = index; i < length; i++) {
		lettertoint = str[i] - 'a';
		if (lettertoint != prelettertoint) {
			return i-1;
		}
	}
}

int checkgroupword(char str[]) {
	for (int i = 0; i < letters.size(); i++) {
		letters[i] = 0;
	}
	int length = strlen(str);
	int lettertoint;
	for (int i = 0; i < length; i++) {
		lettertoint = str[i] - 'a';
		if (letters[lettertoint] == 0) {
			letters[lettertoint] = 1;
			int index = goyeah(str, i+1, lettertoint);
			i = index;
		}
		else {
			return 0; // false
		}
	}
	return 1;
}
int main(void) {
	int test;
	int ans =0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		char str[200];
		cin >> str;
		if (checkgroupword(str) == 1) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}