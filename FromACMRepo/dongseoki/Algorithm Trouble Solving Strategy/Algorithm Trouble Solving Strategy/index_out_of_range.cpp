#include <string>
#include <iostream>
using namespace std;
int main(void) {
	string s = "qwer";
	cout << s.length()<< "\n";
	cout << s.size() << "\n";
	for (int i = 0; i < 5; i++) {
		cout << i << " : " << s[i]<<"\n";
	}
}