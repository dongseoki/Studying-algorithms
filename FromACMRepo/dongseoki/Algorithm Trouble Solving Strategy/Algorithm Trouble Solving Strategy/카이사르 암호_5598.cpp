#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char k_words[1001];
	char r_words[1001] = { 0, };
	cin >> k_words;

	int i = 0;
	while (1) {
		if (k_words[i] == NULL) {
			break;
		}
		r_words[i] = (k_words[i] - 'A' + 26 - 3) % 26 + 'A';

		i++;
	}
	cout << r_words << "\n";
}
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int c;
//	while ((c = getchar()) != '\n')
//		putchar((c - 'A' + 23) % 26 + 'A');
//}