#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int solution(string s) {
    int flag;
    int answer = 0;
    int len = s.length();
    int start = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s[0] == '+')
            flag = 1;
        else
            flag = -1;
        start++;
    }
    else {
        flag = 1;
    }
    answer = stoi(s.substr(start));
    answer *= flag;
    return answer;
}
int main(void) {
    string s = "1234";
    cout << solution(s);
}