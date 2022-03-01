#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& computers, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        cout << here << endl;
        q.pop();
        for (int i = 0; i < computers.size(); i++) {
            if (computers[here][i] == 1 && visited[i] == false) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    int answer = 0;
    vector<bool> visited(computers.size(), false);
    

    for (int i = 0; i < computers.size(); i++) {
        if (visited[i] == false) {
            bfs(i, computers, visited);
            answer++;
        }
    }
    return answer;
}
int main(void) {
    cout << solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} });
}