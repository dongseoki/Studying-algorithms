#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(const pair<float, int > &p1, const pair<float, int >& p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return (p1.first > p2.first);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> challenge_stat(N + 2, 0);
    for (int i = 0; i < stages.size(); i++) {
        challenge_stat[stages[i]]++;
    }
    //for (int i = 0; i < challenge_stat.size(); i++) {
    //    cout << challenge_stat[i] << "\n";
    //}
    vector<int> total_challenge(N + 1, 0);
    int t_c_n = stages.size();
    for (int i = 1; i <= N; i++) {
        t_c_n -= challenge_stat[i - 1];
        total_challenge[i] = t_c_n;
    }
    vector<pair<float, int>> fail_rates;
    for (int i = 1; i <= N; i++) {
        if(total_challenge[i] != 0)
            fail_rates.push_back(make_pair((float)challenge_stat[i] / total_challenge[i], i));
        else {
            fail_rates.push_back(make_pair(0, i));
        }
    }
    //sort(fail_rates.begin(), fail_rates.end(), greater<pair<float,int>>());

    sort(fail_rates.begin(), fail_rates.end(), 
        [](pair<float, int >p1, pair<float, int >p2) -> bool
        {
            if (p1.first == p2.first)
                return p1.second < p2.second;
            return (p1.first > p2.first);
        });

    //sort(fail_rates.begin(), fail_rates.end(), cmp);

    for (int i = 0; i < fail_rates.size(); i++) {
        answer.push_back(fail_rates[i].second);
    }
    return answer;
}

int main(void) {
    int N = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    vector<int> answer = solution(N, stages);
}