#include <string>
#include <vector>
#include <iostream>

using namespace std;

char c_t(char c, int flag) {
    // ���� ���� ���ڷ� ����.
    // ���� �Ǿ��� �빮�ڷ�. ��ȯ
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
            // s[i]�� �빮�ڿ��� ���.
            c_c = c_t(s[i], -1);
        }
        s_word += c_c;
    }
    answer += s_word;
    return i;
}
// �ش� ���ں��� ��Ʈ���� ����� ��ȯ�Ѵ�.
// ù ���� ���ڴ� ������ �ƴϴ�.
// �׸��� ���ڿ��� ��+1�� �ش��ϴ� �ε����� ��ȯ�Ѵ�.
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