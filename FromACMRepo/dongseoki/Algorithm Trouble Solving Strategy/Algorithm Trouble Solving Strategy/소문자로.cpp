#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s1 = "AUX_MU_IO\nAUX_MU_IER\nAUX_MU_IIR\nAUX_MU_LCR\nAUX_MU_MCR\nAUX_MU_LSR\nAUX_MU_MSR\nAUX_MU_SCRATCH\nAUX_MU_CNTL\nAUX_MU_STAT\nAUX_MU_BAUD";

	for (int i = 0; i < s1.size(); i++) {
		if (isalpha(s1[i]) == true) {
			char ch = tolower(s1[i]);
			cout << ch;
		}
		else if (s1[i] == '_')
			cout << "_";
		else
			cout << "\n";
	}

}