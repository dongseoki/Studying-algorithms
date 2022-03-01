#include <iostream>
#include <vector>
#include <string>
using namespace std;

string makeLenStr(int num) {
	if (num ==1) {
		return "1";
	}
	else if (num == 2) {
		return "-2";
	}
	int numLen = to_string(num).length();
	return makeLenStr(num - numLen-1) + "-" + to_string(num);
}

string makeLenStrVer2(long long int num) {
	string ansStr = "";
	long long int restNum = num;
	while (true) {
		if (restNum == 1) {
			ansStr = "1" + ansStr;
			break;
		}
		else if (restNum == 2) {
			ansStr = "-2" + ansStr;
			break;
		}
		else if (restNum < 1) {
			break;
		}
		long long int numLen = to_string(restNum).length();
		ansStr = "-" + to_string(restNum) + ansStr;
		restNum -= (numLen+1);
	}
	if (num >=21) {
		return ansStr.substr(0, 17)+ "...";
	}else
		return ansStr;
}
void INPUT() {
	long long int T = 0;
	long long int a = 0;
	long long int b = 0;
	cin >> T;
	while (T-- > 0) {
		cin >> a;
		cin >> b;
		long long int caseNum = a * pow(10, b);
		cout << makeLenStrVer2(caseNum) << "\n";
	}
}

void rangeTest(long long int start, long long int end) {
	for (int idx = start; idx <= end; idx++) {
		string result = makeLenStrVer2(idx);
		//printf("%10d : %s\n", idx, result);
		cout << idx << " : " << result << "\n";
	}
}
int main(void) {
//	cout << "hello world";
	//cout << makeLenStr(5) << "\n";
	//cout << makeLenStr(8) << "\n";
	//cout << makeLenStr(13)<<"\n";
	//cout << makeLenStr(2) << "\n";
	//cout << "-----------\n";

	cout << makeLenStrVer2(5) << "\n";
	cout << makeLenStrVer2(8) << "\n";
	cout << makeLenStrVer2(13) << "\n";
	cout << makeLenStrVer2(2) << "\n";
	cout << "--Test End---------\n";

	//INPUT();

	//test

	rangeTest(95, 104);
	rangeTest(995, 1004);



}