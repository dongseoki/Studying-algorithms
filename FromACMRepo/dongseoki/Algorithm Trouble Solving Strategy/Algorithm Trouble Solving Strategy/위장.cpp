#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int johap(int cur, int obj, vector<int> & m_vec) {
    int result = 0;
    vector<int> c_vec;
    // always obj <= m_vec.size();
    for (int i = 0; i < obj; i++) {
        c_vec.push_back(1);
   }
    int rest = m_vec.size() - obj;
    for (int i = 0; i < rest; i++) {
        c_vec.push_back(0);
    }
    sort(c_vec.begin(), c_vec.end());
    do {
        int value = 1;
        // 출력
        for (int i = 0; i < m_vec.size(); i++) {
            if (c_vec[i] == 1) {
                value *= m_vec[i];
            }
        }
        result += value;
    } while (next_permutation(c_vec.begin(), c_vec.end()));

    return result;
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //cout << clothes.size() << ": test\n";
    vector<int> m_vec; // mathmatical vector . 수학적 벡터
    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++) {
        //if (m.find(clothes[i][1]) == m.end()) {
        //    // 아직 없다면..
        //    m[clothes[i][1]] = 1;
        //}
        //else {
        //    // 한개라도 있다면
        //    m[clothes[i][1]]++;
        //}
        m[clothes[i][1]]++;
    }

    
   // for (auto i : m) {
   //     m_vec.push_back(i.second);
   //}

    //for (int i = 1; i <= m_vec.size(); i++) {
    //    answer += johap(0, i,m_vec);
    //}

   for (auto i : m) {
       answer *= (i.second + 1);
   }
   answer--;

    
    return answer;
}

int main(void) {
    //cout << solution({ {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} });
    cout << solution({ {"1", "k1"}, { "1","k2" }, { "1","k2" }, { "1","k3" }, { "1","k3" }, { "1","k3" } });

   }