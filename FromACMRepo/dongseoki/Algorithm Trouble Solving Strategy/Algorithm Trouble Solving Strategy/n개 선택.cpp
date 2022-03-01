#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

void try_numbers(int count,int N, vector<map<int, char>>& m_vec, map<int, int>& min_map){
    if (count == 1) {
        m_vec[1][N] = 1;
        min_map[N] = 1;
        return;
    }
    for (auto item : m_vec[count - 1]) {
        int num = item.first* N;
        if (min_map.find(num) == min_map.end()) {
            // min_map 에 없는 값이더라!
            m_vec[count][num]
        }
        // 있던 값이면 아무것도 안함.
    }


}

int solution(int N, int number) {
    int answer = 0;
    vector<map<int, char>> m_vec(9,map<int,char>());
    map<int, int> min_map;
    cout << "....\n";
    for (int i = 1; i < 4; i++) {
        try_numbers(i, N, m_vec, min_map);
    }
    return answer;
}

int main(void) {
    cout << "start";
    solution(5, 12);
}