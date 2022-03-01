#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

bool is_target_inwords(string & target, vector<string> & words, int & t_idx) {
    for (int i = 0; i < words.size();i++) {
        if (target == words[i]) {
            t_idx = i + 1;
            return true;
        }
    }
    // 없는것다.
    return false;
}
bool is_connected(string& s1, string& s2) {
    int flag = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (flag == 0) {
                flag++;
                continue;
            }
            else {
                //flag>=1; 이미. 그런데 다른게 하나더 나온 상황.
                return false;
            }
        }
    }

    if (flag == 1) {
        return true;
    }
    else {
        return false;
    }
}

void make_ad_list(string begin, vector<string>& words, vector<vector<int>>& adjlist) {
    vector<string> v;
    v.push_back(begin);
    
    for (auto i : words) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (is_connected(v[i], v[j]) == true) {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
}
int bfs(vector<vector<int>>& adjlist,int here, int t_idx, int & min_n) {
    queue<int> q;
    vector<int> memo(adjlist.size(), 0);
    vector<bool> visited(adjlist.size(), false);
    memo[here] = 0;
    visited[here] = true;
    q.push(here);

    while (!q.empty()) {
        here = q.front();
        q.pop();
        if (here == t_idx) {
            return memo[here];
        }
        for (int i = 0; i < adjlist[here].size(); i++) {
            int dest = adjlist[here][i];
            if (visited[dest] == false) {
                visited[dest] = true;
                memo[dest] = memo[here] + 1;
                q.push(dest);
            }
        }
    }
    

}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<vector<int>> adjlist(1 + words.size(), vector<int>());
    int t_idx = 0;
    if (is_target_inwords(target, words, t_idx) == false) {
        return 0;
    }

    make_ad_list(begin, words,  adjlist);

    //    //0-> t_idx
    int min_n = numeric_limits<int>::max();
    answer = bfs(adjlist,0, t_idx, min_n);
    
    return answer;
}
int main(void) {
    cout << solution("hit", "cog",{ "hot", "dot", "dog", "lot", "log", "cog" });
}