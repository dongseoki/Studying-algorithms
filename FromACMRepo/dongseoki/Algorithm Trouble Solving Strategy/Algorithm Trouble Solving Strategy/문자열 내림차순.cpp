#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> elements(s.size());
    for (int i = 0; i < s.size(); i++) {
        elements[i] = s[i];
    }
    //cout << "hi";
    sort(elements.begin(), elements.end(), greater<char>());
    for (int i = 0; i < s.size(); i++) {
        answer += elements[i];
    }
    return answer;
}

int main(void) {

    string s = "Zbcdefg";
    cout << solution(s)<<"\n";
}