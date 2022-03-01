#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<int>());
    answer = stoll(s);
    return answer;
}

int main(void) {
    cout << solution(118372);
    return 0;
}