#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

// ����̳� ���� ��ġ�� ���¶�� ����������, �װ��� Ư�� ������ �����ϴ� �� �Ҹ������� ��ȯ�ϴ� �Լ�.

        //----->y
        //|
        //|
        //x

vector<int> dx = { +1,0,-1 };
vector<int> dy = { +1,0,-1 };
bool check(int x, int y, int a, vector<vector <pair<bool, bool>>>& s_map) {
    if (a == 0) {
        // ����̴���.
        if (y == 0)
            return true;
        // ����� �ٴ� ���� �־�.
        if (s_map[x][y].second == true || (x>=1 && s_map[x - 1][y].second == true))
            return true;
        //���� ���� ���κ� ���� �־�.
        if (s_map[x][y - 1].first == true)
            return true;
        //�ٸ� ��� ���� �־�.
    }
    else {
        // ������.
        if (s_map[x][y - 1].first == true || s_map[x + 1][y - 1].first == true)
            return true;
        //���� ���� ���κ��� ��� ���� �ְų�.

        if (x>=1 && s_map[x - 1][y].second == true && s_map[x + 1][y].second == true)
            return true;
        // ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �ִ� ���.
    }

    return false;
    // �� ���ǿ� �ش����� ���� ��� 
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector <pair<bool, bool>>> s_map(n+1, vector<pair<bool, bool>>(1010, make_pair(false,false))); // stuct map.
    //first ���� ����� ������ second ���� ���� ������ ����.
    // -1 ����. 0 ���. 1 ��. 2 ��հ� �� �Ѵ�.
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
                    //����� ��ġ ���.
                    s_map[x][y].first = true;
                }
                else {
                    //�� ��ġ�� ���.
                    s_map[x][y].second = true;
                }
                //��ġ.
            }
            //false. ��ġ ����.
        }
        else  {
            //b==0 �� ���� �ؾߵȴٸ�.
            // ��ó ���鿡���ؼ� ���� �����Ѵٸ� �� ���°� ������ �� üũ�ؾ��Ѵ�.

            //���� �P�ٰ� ����.
            if (a == 0) {
                // ����̴�.
                if (s_map[x][y].first == false) {
                    continue;
                    // �ش� �ڸ��� ����� ���� ��� ���� �Ҽ� ����.
                }
         
                    // ����� �ִ���.
                s_map[x][y].first = false;
            }
            else {
                //�� �̴���.
                if (s_map[x][y].second == false) {
                    continue;
                    // �ش� �ڸ��� ���� ���� ��� ���� �Ҽ� ����.
                }

                // �� �ִ���.
                s_map[x][y].second = false;
            }
            bool deleteOK = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    s_x = x +dx[i];
                    s_y = y + dy[j];
                    if (0 <= s_x && s_x <= n && 0 <= s_y && s_y <= (1010 - 1)) {
                        // ��谪 Ȯ��.
                        // ��賻�� �������.
                        if (s_map[s_x][s_y].first == true) {
                            //����� �ִ���.
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
                //���� �ϸ� �ȵǾ��� �Ŷ��.
                if (a == 0)
                    s_map[x][y].first = true;
                else
                    s_map[x][y].second = true;
            }
            // true�� ���� ���� �״�� ��� ���� ������ ����.
            
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