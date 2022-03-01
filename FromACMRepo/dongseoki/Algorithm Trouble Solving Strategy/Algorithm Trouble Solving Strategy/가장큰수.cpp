#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const int p1, const int p2) {
    string s1 = to_string(p1);
    string s2 = to_string(p2);
    int i = 0;
    while (true) {
        if (s1[i] > s2[i]) {
            i = 0;
            return true;
        }
        if (s1[i] == s2[i]) {
            if (s1.size() == (i+1)) {
                i = 0;
                return true;
            }
            if (s2.size() == (i+1)) {
                i = 0;
                return false;
            }
            i++;
        }
    }
}
bool cmps2(string s1, string s2) {
    return s1 > s2;
}
bool cmps1(string s1, string s2) {
    int i = 0;
    while (true) {
        if (s1[i] > s2[i]) {
           
            return true;
        }
        else if (s1[i] == s2[i]) {
            if (s1.size() == (i + 1) && s2.size() == (i + 1)) {
                return true;
            }
            if (s1.size() == (i + 1)) {
                if (s2[i + 1] == '0') {
                    return true;
                }
                return false;
            }
            if (s2.size() == (i + 1)) {
                if (s1[i + 1] == '0') {
                    return false;
                }
                return true;
            }
            i++;
        }
        else {
            return false;
        }
        
    }
}
bool cmps3(string s1, string s2) {
    return (s1 + s2) > (s2 + s1);
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> n_strings(numbers.size(),"");
    int idx=0;
    for (auto item : numbers) {
        n_strings[idx++] = to_string(item);
    }
    sort(n_strings.begin(), n_strings.end(), cmps3);
    if (n_strings[0] == "0") {
        return "0";
    }
    for (auto item : n_strings) {
        answer += item;
    }
    return answer;
}
int main(void) {
    //cout << solution({ 6, 10, 2 });
//cout << solution({ 3, 30, 34, 5, 9 });
    cout << solution({998,9,999});
    cout << solution({ 0,0,70});
}