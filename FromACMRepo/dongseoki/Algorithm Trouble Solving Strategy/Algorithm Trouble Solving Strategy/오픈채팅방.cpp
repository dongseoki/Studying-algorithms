#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> answer;
    vector<string> m_vec = { "님이 들어왔습니다.", "님이 나갔습니다." };
    vector<pair<int, string>> f_r_vec;
    map<string, string> m;

    int r_size = record.size();
    for (int i = 0; i < r_size; i++) {
        int bl_idx1 = record[i].find(" ");
        int bl_idx2 = record[i].find(" ", bl_idx1 + 1);
        string cmd = record[i].substr(0, bl_idx1);
        string uid = record[i].substr(bl_idx1 +1, bl_idx2- bl_idx1 -1);
        string nick  = record[i].substr(bl_idx2+1);
        //cout << cmd << "\n";
        //cout << uid << "\n";
        //cout << nick << "\n";
        if (cmd == "Enter") {
            m[uid] = nick;
            f_r_vec.push_back(make_pair(0,uid));
        }
        else if (cmd == "Leave") {
            f_r_vec.push_back(make_pair(1, uid));
        }
        else {
            // cmd == "change".
            m[uid] = nick;
        }
        
        
    }

    for (auto item : f_r_vec) {
        answer.push_back(m[item.second] + m_vec[item.first]);
    }

    return answer;
}

int main(void) {
    vector<string> answer =  solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    for (auto item : answer) {
        cout << item << "\n";
    }
    return 0;
}