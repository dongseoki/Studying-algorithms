#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

int times_idx = 0;
bool cmp(pair<int,int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }

    return p1.first < p2.first;
}

void make_int_pair_vec(int idx , vector<string>& lines, vector<pair<int, int>> &times) {
    stringstream ss(lines[idx]);
    string e_s;
    string d_s;
    ss >> e_s;
    ss >> e_s;

    ss >> d_s;

    char* str_buff = new char[1000];
    strcpy(str_buff, e_s.c_str());
    char* tok = strtok(str_buff, ":");
    int hour = atoi(tok);
    tok = strtok(nullptr, ":");
    int min = atoi(tok);
    tok = strtok(nullptr, ".");
    int sec = atoi(tok);
    tok = strtok(nullptr, ".");
    int msec = atoi(tok);

    int e_t = hour * 60 * 60 * 1000;
    e_t += min * 60 * 1000;
    e_t += sec * 1000;
    e_t += msec;

    strcpy(str_buff, d_s.c_str());
    tok = strtok(str_buff, ".");
    sec = atoi(tok);

    if (d_s.find(".") != string::npos) {
        tok = strtok(nullptr, ".");
        msec = atoi(tok);
    }
    else {
        msec = 0;
    }
    
    int d_t = sec * 1000 + msec;

    int s_t = e_t - d_t + 1 - 1000; // 1초 빠르게 하였다.

    //push s_t
    times[times_idx].first = s_t;
    times[times_idx].second = +1;
    times_idx++;
    times[times_idx].first = e_t;
    times[times_idx].second = -1;
    times_idx++;

}

int solution(vector<string> lines) {
    int answer = 0;


    vector<pair<int, int>> times(lines.size() *2, make_pair(0, 0));
    for (int i = 0; i < lines.size(); i++) {
        make_int_pair_vec(i, lines, times);
    }

    sort(times.begin(), times.end());
    int cur = 0;
    vector<int> history(times.size(), 0);
    for (int i = 0; i < times.size(); i++) {
        if (times[i].second == +1) {
            cur++;
        }
        else {
            cur--;

        }
        history[i] = cur;
    }
    answer = *max_element(history.begin(), history.end());

    return answer;
}

int main(void) {
    vector<string> lines = {
"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
    };


    //lines = {"2016-09-15 01:00:04.002 2.0s",
    //    "2016-09-15 01:00:07.000 2s"};
    cout << solution(lines);

    /*string s1 = "123.4123";
    string s2 = "123234";
    cout << s1.find(".") << "\n";
    cout << s2.find(".") << "\n";
    cout << string::npos << "\n";*/

}
