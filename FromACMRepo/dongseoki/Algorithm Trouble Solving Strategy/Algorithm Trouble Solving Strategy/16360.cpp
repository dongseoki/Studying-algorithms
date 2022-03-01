using namespace std;
#include <iostream>
#include <string>
#include <vector>

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	vector<string> english{ "a",	"i",	"y",	"l",	"n",	"ne",	"o",	"r",	"t",	"u",	"v",	"w" };//12°³.
	vector<string> peudo_l{ "as",	"ios",	"ios",	"les",	"anes",	"anes",	"os",	"res",	"tas",	"us",	"ves", "was" };
	while (t--) {
		string str;
		cin >> str;
		int length = str.length();
		int flag = 0;
		for (int i=0; i < 12; i++) {
			int result = str.find(english[i], length - english[i].length());
			if (result != string::npos) {
				cout << str.substr(0, length - english[i].length() ) << peudo_l[i]<<"\n";
				flag = 1;
				break;
			}
		}
		if(flag!=1) {
			cout << str + "us"<< "\n";
		}

	}
}