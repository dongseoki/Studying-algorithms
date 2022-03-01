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
            // case ((() ���� ���� () �� ���
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
    //1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.


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

    //2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�. 
    //��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, 
    //v�� �� ���ڿ��� �� �� �ֽ��ϴ�. 


    if (right_p(u) == true) {
        return (u + solution(v));
    }
    //3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
    //3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.
    else {
        // �ùٸ��� ���� ���.
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