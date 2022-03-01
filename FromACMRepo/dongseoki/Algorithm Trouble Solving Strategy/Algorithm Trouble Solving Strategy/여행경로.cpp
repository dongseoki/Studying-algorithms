#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

bool dfs(string here, int sel_n, int obj_n, vector<vector<string>> &  tickets, unordered_map < string, list<string>> & ump, vector<string> & answer) {

    // 지금 here 에 있고, 방문한 직선의 개수는 sel_n, 방문해야하는 직선의 개수는 obj_n이다.

    // 마침 모든 직선을 다 방문하는 데 성공한 상태다.
    if (sel_n >= obj_n) {
        return true;
    }
    // 모든 점을 방문한 것에 대해 체크 하지 않은 이유는 모든 도시를 방문할 수 없는 경우는 주어지지 않기때문


    // 그렇지 않다면 다른 직선을 이용해 모든 점을 방문하자.
    int pq_size = ump[here].size();

    for (auto iter = ump[here].begin(); iter != ump[here].end(); iter++) {
        string des = *iter;
        auto t_iter = iter;
        t_iter++;
        ump[here].erase(iter);
        answer.push_back(des);
        if (dfs(des, sel_n + 1, obj_n, tickets, ump, answer) == true) {
            return true;
        }
        else {
            answer.pop_back();
            iter = ump[here].insert(t_iter, des);
        }
    }

    //for (auto item : ump[here]) {
    //    string des = item;
    //    ump[here].pop_front();
    //    answer.push_back(des);
    //    if (dfs(des, sel_n + 1, obj_n, tickets, ump, answer) == true) {
    //        return true;
    //    }
    //    else {
    //        answer.pop_back();
    //        ump[here].push_front(des);
    //    }
    //}
    return false;
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    priority_queue < string, vector<string>, greater<string>> pq;
    // 1. make adjacent list. by unordered map.
    unordered_map < string, list<string>> ump;
    
    for (auto item : tickets) {
        string from = item[0];
        string to = item[1];
        ump[from].push_back(to);
    }
    for (auto & item : ump) {
        // 참조자 으..
        // 하도 sort 가 안되다 했더니..
        //sort(item.second.begin(), item.second.end());
        item.second.sort();
        // 역 사전순으로 정렬되더라..
        //item.second.reverse();
        // 사전수으로 바꿈.
    }
    int t_size = tickets.size();
    answer.push_back("ICN");
    dfs("ICN", 0, t_size, tickets, ump, answer);

    return answer;
}

int main(void) {
//    solution({ {"ICN","SFO"},{"ICN","ATL"},{"SFO","ATL"},{"ATL","ICN"},{"ATL","SFO"}});
    solution({ {"ICN","COO"},{"ICN","BOO"},{"COO","ICN"},{"BOO","DOO"}});
}