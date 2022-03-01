#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

bool dfs(string here, int sel_n, int obj_n, vector<vector<string>> &  tickets, unordered_map < string, list<string>> & ump, vector<string> & answer) {

    // ���� here �� �ְ�, �湮�� ������ ������ sel_n, �湮�ؾ��ϴ� ������ ������ obj_n�̴�.

    // ��ħ ��� ������ �� �湮�ϴ� �� ������ ���´�.
    if (sel_n >= obj_n) {
        return true;
    }
    // ��� ���� �湮�� �Ϳ� ���� üũ ���� ���� ������ ��� ���ø� �湮�� �� ���� ���� �־����� �ʱ⶧��


    // �׷��� �ʴٸ� �ٸ� ������ �̿��� ��� ���� �湮����.
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
        // ������ ��..
        // �ϵ� sort �� �ȵǴ� �ߴ���..
        //sort(item.second.begin(), item.second.end());
        item.second.sort();
        // �� ���������� ���ĵǴ���..
        //item.second.reverse();
        // ���������� �ٲ�.
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