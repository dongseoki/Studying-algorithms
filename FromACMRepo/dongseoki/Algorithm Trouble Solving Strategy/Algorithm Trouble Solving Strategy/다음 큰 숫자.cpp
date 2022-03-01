#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n) {
    int answer = 0;
    queue<int> q;
    vector<int> v2;
    int check = 1<<24;
    for (int i = 0; i < 25; i++) {
        if ((n & check) == 0) {
            v2.push_back(0);
        }
        else {
            v2.push_back(1);
        }
        check = check >> 1;
    }

    next_permutation(v2.begin(), v2.end());

    for (int i = 0; i < 25; i++) {
        if (v2[i] == 1) {
            answer += 1;
        }
        // 0 이다. 그럼 아무것도.
        if(i != 24)
            answer = answer << 1;
    }

    return answer;
}

int main(void) {
    cout <<solution(78);
}