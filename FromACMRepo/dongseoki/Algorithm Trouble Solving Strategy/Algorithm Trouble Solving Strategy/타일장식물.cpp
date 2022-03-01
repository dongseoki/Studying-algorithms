#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int N) {

    if (N == 1)
        return 4;
    long long answer = 0;
    long long pre = 1;
    long long cur = 1;
    for (int i = 3; i <= N; i++) {
        long long temp = pre;
        pre = cur;
        cur = temp + cur;
    }

    answer = cur * 4 + pre * 2;
        return answer;
}

int main(void) {
    cout << solution(6);
}