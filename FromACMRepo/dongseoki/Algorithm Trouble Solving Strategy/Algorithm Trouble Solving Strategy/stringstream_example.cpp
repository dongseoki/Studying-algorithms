#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int main(void) {
	string str1 = "hi my name is dongseoki";
	stringstream ss;
	ss.str(str1);
	string word;
	while (ss >> word) cout << "word: " << word << endl; // displays wordbers, one per line

}