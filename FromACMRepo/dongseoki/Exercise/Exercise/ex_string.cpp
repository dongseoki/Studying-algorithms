
#include <iostream>

using namespace std;
int main(void) {
	string r;
	r = " hello world";

	int s= r.find("llo");
	cout << s<<"\n";

	s = r.find("llso");
	cout << s << "\n";
}