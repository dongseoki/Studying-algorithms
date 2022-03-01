#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> d(land.size(), vector<int>(4, 0));
    for (int i = 0; i < 4; i++) {
        d[0][i] = land[0][i];
    }

    int r_len = land.size();
    if (r_len == 1) {
        return *max_element(d[0].begin(), d[0].end());
    }
    int max_n = -1;
    for (int r = 1; r< r_len; r++) {
        for (int c = 0; c < 4; c++) {
            max_n = -1;
            for (int j = 0; j < 4; j++) {
                if (j == c)
                    continue;
                max_n = max(max_n, d[r - 1][j]);
            }
            d[r][c] = max_n+land[r][c];
        }
    }
    max_n = -1;
    for (int c = 0; c < 4; c++) {
        answer = max(answer, d[r_len - 1][c]);
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
   // cout << "Hello Cpp" << endl;

    return answer;
}

int main(void) {
    cout << solution({ {1,2,3,5},{5,6,7,8},{4,3,2,1} });
}