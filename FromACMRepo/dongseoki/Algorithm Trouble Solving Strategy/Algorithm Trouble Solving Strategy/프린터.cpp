#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<int> priorities, int location) {
    //https://twpower.github.io/93-how-to-use-priority_queue-in-cpp

    vector<int> sequence;

    priority_queue<int> pq;
    queue<pair<int, int>> q;
    int num = 0;

    for (auto i : priorities) {
        pq.push(i);
        q.push(make_pair(num,i));
        num++;
    }
    int count = 0;
    while (true) {
        pair<int,int> t_item = q.front(); // top item.
        q.pop();
        

        int max_item = pq.top();
        if (t_item.second < max_item) {
            q.push(t_item);
        }
        else {
            count++;

            //t_item.second == max_item
            //sequence.push_back(t_item.first);
            pq.pop();
            if (t_item.first == location) {
                // 하고 싶은거.
                break;
            }
        }
    }
    int answer = count;
    return answer;
}

int main(void) {
//    cout << "solution : " << solution({ 2, 1, 3, 2 }, 2);
    cout << "solution : " << solution({ 1, 1, 9, 1, 1, 1 }, 0);
    //[1, 1, 9, 1, 1, 1]	0	5
}