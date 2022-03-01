#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> points(3, 0);
    int p_index = 0;
    int i = 0;

    while (true) {
        if (i >= dartResult.size() || p_index >=3)
            break;
        points[p_index] = dartResult[i] - '0';
        i++;
        if (dartResult[i - 1] == '1' && dartResult[i] == '0') {
            // 점수가 10이였을때,
            points[p_index] = 10;
            i++;
        }

        switch (dartResult[i]) {
        case 'S':
            points[p_index] = pow(points[p_index], 1);
            break;
        case 'D':
            points[p_index] = pow(points[p_index], 2);
            break;
        case 'T':
            points[p_index] = pow(points[p_index], 3);
            break;
        }
        i++;
        if (dartResult[i] == '#' || dartResult[i] == '*') {
            if (dartResult[i] == '*') {
                //  스타상
                points[p_index] *= 2;
                if (p_index - 1 >= 0) {
                    points[p_index - 1] *= 2;
                }
            }
            else {
                // 아차상 #
                points[p_index] *= (-1);
            }
            i++;
        }
        p_index++;
    }
    for (int j = 0; j < 3; j++) {
        //cout << points[j]<< "\n";
        answer += points[j];
    }
    return answer;
}

int main(void) {
    //cout << "---------solution--------\n";
    cout << solution("1D2S#10S");
}