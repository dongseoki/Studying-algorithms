#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    //for (auto i : scoville) {
    //    pq.push(i);
    //}
    while (true) {
        if (pq.top() >= K) {
            break;
        }
        if (pq.size() <= 1) {
            return -1;
        }
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        pq.push(s1 + s2 * 2);
        answer++;
    }


    return answer;
}

int main(void) {
    cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);
}