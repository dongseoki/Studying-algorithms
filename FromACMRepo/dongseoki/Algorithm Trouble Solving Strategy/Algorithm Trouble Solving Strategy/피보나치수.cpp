#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int pre = 0;
    int cur = 1;
    if (n == 0)
        return pre;
    if (n == 1)
        return cur;

    int temp = 0;
    for (int i = 2; i <= n; i++) {
        temp = pre;
        pre = cur;
        cur = (temp + cur)%1234567;
    }
    answer = cur;
    return answer;
}

int main(void) {
    cout << solution(5);
}