#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
class Robot {
public:
    int r;
    int c;
    int d; // direction
    //   1
    //2     0
    //   3
    Robot(int r, int c, int d) {
        this->r = r;
        this->c = c;
        this->d = d;
    };
};

vector<int> dr = { 0,-1,0,+1 };
vector<int> dc = { +1,0,-1,0 };
bool boundary_check(int s_r, int s_c, int s_r2, int s_c2, int n) {
    // n = board.size() -1;
    if (0 <= s_r && s_r <= n &&0 <= s_c && s_c <= n && 0 <= s_r2 && s_r2 <= n && 0 <= s_c2 && s_c2 <= n) {
        return true;
    }
    else
        return false;
}
bool not_wall_check(int s_r, int s_c, vector<vector<int>>& board) {
    if (board[s_r][s_c] == 0)
        return true;
    else
        return false;
    // 0은 길.,  1은 벽.
}

void spin_robot(Robot rb, int p_m, int n, vector<vector<vector<int>>>& d_map, queue<Robot>& q, vector<vector<int>>& board) {
    int s_d = (rb.d + p_m + 4) % 4;
    int s_r = rb.r + dr[s_d];
    int s_c = rb.c + dc[s_d];
    int c_pos_r = rb.r + dr[rb.d] + dr[s_d];
    int c_pos_c = rb.c + dc[rb.d] + dc[s_d];
    if (boundary_check(s_r, s_c, c_pos_r, c_pos_c, n) == true 
        && not_wall_check(s_r, s_c, board) == true
        && not_wall_check(c_pos_r, c_pos_c, board) == true) {
        if (d_map[rb.r][rb.c][s_d] == -1 || d_map[s_r][s_c][(s_d + 2) % 4] == -1) {
            // 아직 안본 점 + 로봇 방향 이라면.
            int num = max(d_map[rb.r][rb.c][rb.d], d_map[(rb.r + dr[rb.d])][(rb.c + dc[rb.d])][(rb.d + 2) % 4]);
            if(d_map[rb.r][rb.c][s_d] == -1)
                d_map[rb.r][rb.c][s_d] = num + 1;
            if(d_map[s_r][s_c][(s_d + 2) % 4] == -1)
                d_map[s_r][s_c][(s_d + 2) % 4] = num + 1;
            q.push(Robot(rb.r, rb.c, s_d));
        }
    }
}
void move_news_robot(Robot rb, int i, int n, vector<vector<vector<int>>>& d_map, queue<Robot>& q, vector<vector<int>>& board) {
    int s_r = rb.r + dr[i];
    int s_c = rb.c + dc[i];
    int s_r2 = (rb.r + dr[rb.d]) + dr[i];
    int s_c2 = (rb.c + dc[rb.d]) + dc[i];
    if (boundary_check(s_r, s_c, s_r2, s_c2, n) == true && not_wall_check(s_r, s_c, board) == true && not_wall_check(s_r2, s_c2, board) == true) {
        // 로봇이 경계 내에 있다면.
        // 그리고 해당 구역이 벽이 아니라면.
        if (d_map[s_r][s_c][rb.d] == -1 || d_map[s_r2][s_c2][(rb.d + 2) % 4] == -1) {
            // 아직 안본 점 + 로봇방향이라면.
            int num = max(d_map[rb.r][rb.c][rb.d], d_map[(rb.r + dr[rb.d])][(rb.c + dc[rb.d])][(rb.d + 2) % 4]);
            if(d_map[s_r][s_c][rb.d] == -1)
                d_map[s_r][s_c][rb.d]  = num +1;
            if(d_map[s_r2][s_c2][(rb.d + 2) % 4] == -1)
                d_map[s_r2][s_c2][(rb.d + 2) % 4] = num +1;
            q.push(Robot(s_r, s_c, rb.d));
        }
    }
}
void print_d_map(int n, int mode, vector<vector<vector<int>>>& d_map) {
    cout << "mode :" << mode << "\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            
            //cout << d_map[i][j][mode] << " ";
        }
        cout << "\n";
    }
    cout << "------\n\n";
}

void print_good_d_map(int n,string sp, int nomatter, vector<vector<vector<int>>>& d_map) {
    for (int i = 0; i < 4; i++) {
        cout << "m" << i;
        for (int a = 0; a < (n); a++)
            cout << sp<<"__";
        cout << sp<<sp;
    }
        
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        for (int mode = 0; mode < 4; mode++) {
            for (int j = 0; j <= n; j++) {
                printf("%2d", d_map[i][j][mode]);
                cout << sp;
                //cout << d_map[i][j][mode] << sp;
            }
            cout << sp;
        }
        cout << "\n";
    }
    cout << "\n--------------------\n";
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size() - 1;
    // start point
    // (0,0), (0,1)
    //end point. (n,n)
    //방향.
    //   1
    //2     0
    //   3
    vector<vector<vector<int>>> d_map(board.size(), vector<vector<int>>(board.size(), vector<int>(4, -1)));
    vector<vector<vector<bool>>> visited(board.size(), vector<vector<bool>>(board.size(), vector<bool>(4, false)));
    queue<Robot> q;
    d_map[0][0][0] = 0;
    d_map[0][1][2] = 0;
    visited[0][0][0] = true;
    visited[0][1][2] = true;
    //  초기 자동차 상태.

    q.push(Robot(0, 0, 0)); // 0->
    q.push(Robot(0, 1, 2)); // <-0 상태를 말함.
    int count = 0;
    while (!q.empty()) {
        cout << ++count << "\n";
        //if (count == 101) {
        //    cout << "here\n";
        //}
        print_good_d_map(n, "  ",0, d_map);
        Robot rb = q.front();
        q.pop();
        if ((rb.r == n && rb.c == n) ||
            ((rb.r + dr[rb.d]) == n
                && (rb.c + dc[rb.d]) == n)
            ) {

            break;
        }
        // 찾았다
        
        
        Robot n_rb = Robot(rb.r + dr[rb.d], rb.c + dc[rb.d], (rb.d + 2) % 4);
        for (int i = 0; i < 8; i++) {
            if (0 <= i && i <= 3) {
                move_news_robot(rb, i, n, d_map, q, board);
            }
            if (4 <= i) {
                switch (i) {
                    case 4:
                        spin_robot(rb, +1, n, d_map, q, board);
                        break;
                    case 5: 
                        //print_good_d_map(n, -1, d_map);
                        spin_robot(rb, -1, n, d_map, q, board);
                        break;
                    case 6:
                        spin_robot(n_rb, +1, n, d_map, q, board);
                        break;
                    case 7:
                        spin_robot(n_rb, -1, n, d_map, q, board);
                        break;
                }
            }
            //print_good_d_map(n, "  ", -1, d_map);
        }

    }

    print_good_d_map(n,"  ",-1, d_map);

    answer = 200000000; // 2억.
    for (int i = 0; i < 4; i++) {
        if (d_map[n][n][i] != -1) {
            if (answer > d_map[n][n][i])
                answer = d_map[n][n][i];
        }
    }
    return answer;
}


int main(void) {
    //cout << solution({ {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });
    //cout << solution({ {0,0,1,1,0,0},
    //        {0,0,0,0,0,0},
    //        {1,1,1,1,1,0},
    //        {1,1,1,1,1,0},
    //        {1,1,1,1,0,0},
    //        {0,0,0,0,0,0} }
    //        );
    //cout << solution({ {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0}
    //    });
    cout<<solution({ 
    {	0	,	0	,	1	,	0	,	1	,	0	,	0	,	1	,	0	,	0	}	,
    {	0	,	0	,	1	,	0	,	1	,	0	,	0	,	0	,	0	,	0	}	,
    {	1	,	0	,	1	,	1	,	1	,	0	,	0	,	1	,	1	,	0	}	,
    {	1	,	0	,	0	,	0	,	0	,	0	,	1	,	1	,	0	,	0	}	,
    {	1	,	0	,	0	,	0	,	1	,	0	,	0	,	1	,	0	,	0	}	,
    {	1	,	1	,	1	,	0	,	1	,	0	,	0	,	0	,	0	,	1	}	,
    {	1	,	1	,	0	,	0	,	1	,	0	,	0	,	0	,	0	,	0	}	,
    {	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	1	,	0	}	,
    {	0	,	0	,	1	,	1	,	0	,	0	,	1	,	0	,	0	,	1	}	,
    {	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	} }
    );

}