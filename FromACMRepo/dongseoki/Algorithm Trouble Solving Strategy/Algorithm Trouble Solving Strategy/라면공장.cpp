#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
struct d_s {

};

struct a {
    int start;
    int end;
    int value;
};

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return true;
}


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int today = 0;
    int d_idx = 0;
    int d_size = dates.size();
    priority_queue<int> pqhl;
    while (true) {
        today += stock;
        if (today >= k) {
            break;
        }
        while (true) {
            if (d_idx >= d_size) {
                break;
            }
            if (dates[d_idx] <= today) {
                pqhl.push(supplies[d_idx]);
                d_idx++;
            }
            else {
                break;
            }
        }

        answer++;

        stock = pqhl.top();
        pqhl.pop();
    }
    

    return answer;
}

int main(void) {
    cout << solution(4, { 4, 10, 15 }, { 20, 5, 10 }, 30);
}