#include <string>
#include <vector>
#include <iostream>

using namespace std;

char c_t(char c, int flag) {
    // 받은 것은 문자로 가정.
    // 뭐가 되었든 대문자로. 변환
    if ('a' <= c && c <= 'z') {
        c -= 32;
    }

    if (flag == +1) {
        return c;
    }
    else {
        // flag == -1;
        c += 32;
        return c;
    }
}

int strangeWord(int start, string& s, int size, string& answer) {
    size = s.length();
    int i;
    string s_word = "";
    char c_c;//converted character
    for (i = start; i < size; i++) {
        if (s[i] == ' ') {
            s_word += ' ';
            break;
        }

        if ((i - start) % 2 == 0) {
            c_c = c_t(s[i], +1);
        }
        else {
            // s[i]가 대문자였던 경우.
            c_c = c_t(s[i], -1);
        }
        s_word += c_c;
    }
    answer += s_word;
    return i;
}
// 해당 문자부터 스트링을 만들어 반환한다.
// 첫 시작 문자는 공백이 아니다.
// 그리고 문자열의 끝+1에 해당하는 인덱스를 반환한다.
string solution(string s) {
    string answer = "";
    int size = s.length();
    //int strangeWord(int start, string s, int size, string & answer)
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            answer += ' ';
            continue;
        }
        else {
            i = strangeWord(i, s, size, answer);
        }
    }
    return answer;
}

int main(void) {
    cout << solution("try hello  ");
    cout << "##\n";
}