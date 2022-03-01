#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_max_index(int s, int e, string & number) {
    int max_idx = -1;
    int max_num = -1;
    for (int i = s; i <= e; i++) {
        if (max_num<(number[i]-'0')) {
            max_num = number[i] - '0';
            max_idx = i;
        }
    }

    return max_idx;
}

string solution(string number, int k) {
    string answer = "";
    int s_len = number.size() -k; // select length.
    int s_idx = 0;
    int e_idx = number.size() - s_len;
    for (int i = 0; i < s_len; i++) {
        int index = find_max_index(s_idx,e_idx, number);
        
        answer += number[index];

        s_idx = index+1;
        e_idx++;
    }
    

    return answer;
}

int main(void) {
    cout << solution("4177252841", 4);
}