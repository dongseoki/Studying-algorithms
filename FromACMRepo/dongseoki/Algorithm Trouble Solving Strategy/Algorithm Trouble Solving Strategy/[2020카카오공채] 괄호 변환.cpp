#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool right_p(string p) {
    vector<char> st;
    int p_len = p.length();
    for (int i = 0; i < p_len; i++) {
        st.push_back(p[i]);
        if (st.size() >=2  && st[st.size() - 2] == '(' && st[st.size() - 1] == ')') {
            // case ((() 에서 끝에 () 인 경우
            st.pop_back();
            st.pop_back();
        }
    }
    if (st.size() == 0) {
        return true;
    }
    else
        return false;
    
}

string t_b_direction_reverse(int start, int end, string u) {
    string r_u ="";
    for (int i = start; i <= end; i++) {
        if (u[i] == '(') {
            r_u += ")";
        }
        else {
            r_u += "(";
        }
    }
    return r_u;
}

string solution(string p) {
    string answer = "";
    if (p == "")
        return "";
    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.


    int lpc = 0; // left parentheses count;
    int rpc = 0;

    int u_len = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') {
            lpc++;
        }
        else {
            // (p[i] == ')')
            rpc++;
        }
        if (lpc >= 1 && lpc == rpc) {
            u_len = i + 1;
            break;
        }
    }
    string u = p.substr(0, u_len);
    string v = p.substr(u_len);

    //2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 
    //단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, 
    //v는 빈 문자열이 될 수 있습니다. 


    if (right_p(u) == true) {
        return (u + solution(v));
    }
    //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    //3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
    else {
        // 올바르지 않을 경우.
        answer = "(";
        answer += solution(v);
        answer += ")";
        answer += t_b_direction_reverse(1, u.length() - 2, u);
        return answer;
    }
}

int main(void) {
    cout << solution("()))((()");
    return 0;
}