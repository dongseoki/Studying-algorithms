
#include <string>
#include <vector>

using namespace std;

string solution(string phrases, int second) {
	int phase = second % 28;
	string answer = "______________";

	if (phase == 0) {
		//cout<<answer;
	}
	else if (1 <= phase && phase <= 14) {
		int j = 0;
		for (int i = 14 - phase; i <= 13; i++) {
			answer[i] = phrases[j];
			j++;
		}
	}
	else {
		//15를 넘어간 경우
		int j = 0;
		for (int i = phase - 14; i <= 13; i++) {
			answer[j] = phrases[i];
			j++;
		}

	}
	//string answer = "";
	return answer;
}