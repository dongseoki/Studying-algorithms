#include <string>
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    answer = numeric_limits<long long>::max();
    sort(times.begin(), times.end());
    long long low = 0;
    long long high = (long long)times.back() * n;
    while (low <= high) {
        long long mid = (low + high) / 2;
        //mid는 예상 측정 분. 이정도 분 걸리지 않을까.

        //이제 mid 동안 얼마나 많은 사람을 처리할 수 있었는지 보자.
        long long maxnum = 0;
        for (auto item : times) {
            maxnum += (mid / item);
        }

        if (n <= maxnum)
        {
            high = mid-1;
            if (answer > mid) {
                answer = mid;
            }
        }
        else {
            low = mid+1;
            // maxnum
        }
    }
    return answer;
}

int main(void) {
    cout << solution(6, { 7,10 });
}