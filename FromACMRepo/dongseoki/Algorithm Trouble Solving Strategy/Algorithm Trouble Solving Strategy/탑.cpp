#include <string>
#include <vector>
#include <iostream>

using namespace std;

int top(int x, vector<int>& heights, vector<int>& answer) {
    int& ref = answer[x];
    if (ref != -1) {
        return ref;
    }

    // answer[x] 가 -1 이라면
    if (x == 1) {
        ref = 0;
        return ref;
    }
    if (heights[x - 2]> heights[x-1]) {
        ref = x - 1;
        return ref;
    }
    else if (top(x - 1, heights, answer) > heights[x-1]) {
        ref = answer[x - 1];
        return ref;
    }
    else {
        ref = 0;
        return ref;
    }
}

vector<int> solution(vector<int> heights) {
    int h_size = heights.size();
    vector<int> answer(h_size, -1);
    answer[0] = 0;
    for (int i = 2; i <= h_size; i++) {
        if (heights[i - 2] > heights[i - 1]) {
            answer[i-1] = i - 1;
        }
        else if(answer[i - 1 - 1] == 0){
            answer[i - 1] = 0;
        }
        else if(heights[answer[i-1 -1] -1] > heights[i - 1]) {
            answer[i-1] = answer[i-1 - 1];
        }
        else {
            answer[i - 1] = 0;
        }
    }
    return answer;
}


int main(void) {
    vector<int> answer = solution({ 6, 9, 5, 7, 4 });
    for (auto & item : answer) {
        cout << item << " ";
    }
    return 0;
}