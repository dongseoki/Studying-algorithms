#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

// 기둥이나 보를 설치된 상태라고 가정했을때, 그것이 특정 조건을 만족하는 지 불린형으로 반환하는 함수.

        //----->y
        //|
        //|
        //x

vector<int> dx = { +1,0,-1 };
vector<int> dy = { +1,0,-1 };
bool check(int x, int y, int a, vector<vector <pair<bool, bool>>>& s_map) {
    if (a == 0) {
        // 기둥이더라.
        if (y == 0)
            return true;
        // 기둥이 바닥 위에 있어.
        if (s_map[x][y].second == true || (x>=1 && s_map[x - 1][y].second == true))
            return true;
        //보의 한쪽 끝부분 위에 있어.
        if (s_map[x][y - 1].first == true)
            return true;
        //다른 기둥 위에 있어.
    }
    else {
        // 보더라.
        if (s_map[x][y - 1].first == true || s_map[x + 1][y - 1].first == true)
            return true;
        //보의 한쪽 끝부분이 기둥 위에 있거나.

        if (x>=1 && s_map[x - 1][y].second == true && s_map[x + 1][y].second == true)
            return true;
        // 양쪽 끝 부분이 다른 보와 동시에 연결되어 있는 경우.
    }

    return false;
    // 위 조건에 해당하지 않을 경우 
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector <pair<bool, bool>>> s_map(n+1, vector<pair<bool, bool>>(1010, make_pair(false,false))); // stuct map.
    //first 에는 기둥의 유무가 second 에는 보의 유무가 들어간다.
    // -1 없음. 0 기둥. 1 보. 2 기둥과 보 둘다.
    int x, y, a, b;

    int s_x=0;
    int s_y=0;
    for (auto cmd : build_frame) {
        x = cmd[0];
        y = cmd[1];
        a = cmd[2];
        b = cmd[3];
        if (b == 1) {
            if (check(x, y, a, s_map) == true) {
                if (a == 0) {
                    //기둥의 설치 경우.
                    s_map[x][y].first = true;
                }
                else {
                    //보 설치의 경우.
                    s_map[x][y].second = true;
                }
                //설치.
            }
            //false. 설치 안함.
        }
        else  {
            //b==0 즉 삭제 해야된다면.
            // 근처 값들에대해서 뭔가 존재한다면 그 상태가 괜찮은 지 체크해야한다.

            //먼저 뻇다고 가정.
            if (a == 0) {
                // 기둥이다.
                if (s_map[x][y].first == false) {
                    continue;
                    // 해당 자리에 기둥이 없던 경우 삭제 할수 없다.
                }
         
                    // 기둥이 있더라.
                s_map[x][y].first = false;
            }
            else {
                //보 이더라.
                if (s_map[x][y].second == false) {
                    continue;
                    // 해당 자리에 보가 없던 경우 삭제 할수 없다.
                }

                // 보 있더라.
                s_map[x][y].second = false;
            }
            bool deleteOK = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    s_x = x +dx[i];
                    s_y = y + dy[j];
                    if (0 <= s_x && s_x <= n && 0 <= s_y && s_y <= (1010 - 1)) {
                        // 경계값 확인.
                        // 경계내에 있을경우.
                        if (s_map[s_x][s_y].first == true) {
                            //기둥이 있더라.
                            if (check(s_x, s_y, 0, s_map) == false) {
                                deleteOK = false;
                            }
                        }
                        if (s_map[s_x][s_y].second == true) {
                            if (check(s_x, s_y, 1, s_map) == false) {
                                deleteOK = false;
                            }
                        }
                    }
                }
            }

            if (deleteOK == false) {
                //삭제 하면 안되었던 거라면.
                if (a == 0)
                    s_map[x][y].first = true;
                else
                    s_map[x][y].second = true;
            }
            // true면 삭제 한테 그대로 계속 다음 동작을 진행.
            
            //
        }
    }

    vector<vector<int>> answer;

    for (int i = 0; i < (n+1); i++) {
        for (int j = 0; j < 1010; j++) {
            if (s_map[i][j].first == true)
                answer.push_back({ i,j,0 });
            if (s_map[i][j].second == true)
                answer.push_back({ i,j,1 });
        }
    }
    return answer;
}

int main(void) {
    vector<vector<int>> build_frame = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    build_frame = { {0, 0, 0, 1}, { 2,0,0,1 }, { 4,0,0,1 }, { 0,1,1,1 }, { 1,1,1,1 }, { 2,1,1,1 }, { 3,1,1,1 }, { 2,0,0,0 }, { 1,1,1,0 }, { 2,2,0,1 }};
    solution(5, build_frame);
}