#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void make_multiset_elements(string & str1, map<string, int>& m) {
    for (int i = 0; i < str1.size() - 1; i++) {
        string ele = "";
        ele += tolower(str1[i]);
        ele += tolower(str1[i+1]);
        if (('a' <= ele[0] && ele[0] <= 'z') && ('a' <= ele[1] && ele[1] <= 'z')) {
            m[ele]++;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1;
    map<string, int> m2;
    map<string, int> m_orset;
    make_multiset_elements(str1, m1);
    make_multiset_elements(str2, m2);

    if (m1.empty() && m2.empty()) {
        return 65536;
    }

    int andsetnum = 0;
    for (auto item : m1) {
        if (m2.find(item.first) != m2.end()) {
            // 무언가 있다.
            andsetnum += min(item.second, m2[item.first]);
        }
        m_orset[item.first] = item.second;
    }

    for (auto item : m2) {
        if (m1.find(item.first) != m1.end()) {
            // 무언가 있다.
            m_orset[item.first] =  max(item.second, m1[item.first]);
        }
        else {
            // 무언가 없다.
            m_orset[item.first] = item.second;
        }
    }


    int orsetnum = 0;
    for (auto item : m_orset) {
        orsetnum += item.second;
        
    }

    answer = (double(andsetnum) / orsetnum) * 65536;


    
    return answer;
}

int main(void) {

    cout << solution("aa1+aa2","AAAA12");
}