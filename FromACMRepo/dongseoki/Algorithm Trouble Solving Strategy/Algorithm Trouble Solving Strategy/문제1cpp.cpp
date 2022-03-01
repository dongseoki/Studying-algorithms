#include <iostream>
#include <vector>
using namespace std;
vector<int> segment_display = {6,2,5,5,4,5,6,3,7,6};
/*string make_string(string made_string, int cnt, int obj, int avail) {
	if (cnt > obj) {
		return made_string;
	}
	for (int i = 9; i >= 0; i--) {
		if (segment_display[i] <= avail) {
			int residue = avail - segment_display[i];
			make_string(residue )
			break;
*/

string solution(int input) {
	int share = input / 2;
	string answer = "";
	if (input % 2 == 1) {
		if (input >= 3) {
			share--;
			answer += "7";
		}
	}
	for (int i = 0; i < share; i++)
		answer += "1";
	return answer;
}
int main() {
	//char input[100];
	int input;
	cin >> input;
	cout<<solution(input);
	//cout << "Hello Goorm! Your input is " << input << endl;
	return 0;
}