#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, "");

    // 해석해서 결과를 배열에 저장하자.
    vector<int> r_map(n, 0);
    for (int i = 0; i < n; i++) {
        r_map[i] = arr1[i] | arr2[i];
    }
    //for (int i = 0; i < n; i++) {
    //    cout<< r_map[i]<<"\n";
    //}
    //cout << "test\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int checkpoint = pow(2, n - 1 - j);
            if ((r_map[i] & checkpoint) == checkpoint) {
                // 벽이다
                answer[i] += "#";
            }
            else {
                // 공백이다.
                answer[i] += " ";
            }
        }
    }
    return answer;
}

int main(void) {
    int n = 5;
    vector<int> arr1 = { 9,20,28,18,11 };
    vector<int > arr2 = { 30,1,21,17,28 };
    vector<string> answer = solution(n, arr1, arr2);
    for(string s : answer)
    {
        cout << s<<"\n";
    }
}