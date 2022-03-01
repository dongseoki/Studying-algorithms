#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define F(p,q,r) for(int p=q;p<r;p++)

vector<vector<char>> screen = { {'1','2','3' },{'4','5','6' } ,{'7','8','9' } ,{'*','0','#' } };

pair<int, int> findNumPos(int num, vector<vector<char>>& screen) {
    F(i, 0, screen.size()) {
        F(j, 0, screen[0].size()) {
            if (screen[i][j] == num) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

int caculateDistance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string touchNumber(int num, string hand, pair<int, int>& leftPos, pair<int, int>& rightPos) {
    

    pair<int, int> numPos = findNumPos(num, screen);
    num = num - '0';
    // 변호나
    if ((num - 1) % 3 == 0) {
        // 왼손.
        leftPos = numPos;
        return "L";

    }
    else if (num % 3 == 0 && num != 0) {
        //오른손
        rightPos = numPos;
        return "R";
    }
    else {
        // 기타.
        int leftDistance = caculateDistance(numPos, leftPos);
        int rightDistance = caculateDistance(numPos, rightPos);
        if (leftDistance < rightDistance) {
            leftPos = numPos;
            return "L";
        }
        else if (leftDistance > rightDistance) {
            rightPos = numPos;
            return "R";
        }
        else {
            if (hand == "right") {
                rightPos = numPos;
                return "R";
            }
            else {
                leftPos = numPos;
                return "L";
            }
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> leftPos = make_pair(3, 0);
    pair<int, int> rightPos = make_pair(3, 2);
    for (int i = 0; i < numbers.size(); i++) {
        string result = touchNumber(numbers[i] + '0', hand, leftPos, rightPos);
        answer += result;
    }
    return answer;
}
int main(void) {
	//cout << "hi";
//    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
//    string hand = "right";
    //vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    //string hand = "right";
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    string hand = "left";
    cout <<solution(numbers, hand);
}

