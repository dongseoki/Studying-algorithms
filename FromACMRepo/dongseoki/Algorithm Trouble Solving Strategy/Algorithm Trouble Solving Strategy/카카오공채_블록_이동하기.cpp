#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>

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
    if (0 <= s_r && s_r <= n &&
        0 <= s_c && s_c <= n &&
        0 <= s_r2 && s_r2 <= n &&
        0 <= s_c2 && s_c2 <= n) {
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
    // 0�� ��.,  1�� ��.
}

void spin_robot(Robot rb, int p_m, int n, vector<vector<vector<int>>>& d_map, queue<Robot>& q, vector<vector<int>>& board) {
    int s_d = (rb.d + p_m + 4) % 4;
    int s_r = rb.r + dr[s_d];
    int s_c = rb.c + dc[s_d];
    int c_pos_r = rb.r + dr[rb.d] + dr[s_d];
    int c_pos_c = rb.c + dc[rb.d] + dc[s_d];
    if (boundary_check(s_r, s_c, c_pos_r, c_pos_c, n) == true
        && not_wall_check(s_r, s_c, board) == true) {
        if (d_map[rb.r][rb.c][s_d] == -1 || d_map[s_r][s_c][(s_d + 2) % 4] == -1) {
            // ���� �Ⱥ� �� + �κ� ���� �̶��.

            d_map[rb.r][rb.c][s_d] = d_map[rb.r][rb.c][rb.d] + 1;
            d_map[s_r][s_c][(s_d + 2) % 4] = d_map[rb.r][rb.c][rb.d] + 1;
            q.push(Robot(rb.r, rb.c, s_d));
        }
    }
}
void move_news_robot(Robot rb, int i, int n, vector<vector<vector<int>>>& d_map, queue<Robot>& q, vector<vector<int>>& board) {
    int s_r = rb.r + dr[i];
    int s_c = rb.c + dc[i];
    int s_r2 = (rb.r + dr[rb.d]) + dr[i];
    int s_c2 = (rb.c + dr[rb.d]) + dc[i];
    if (boundary_check(s_r, s_c, s_r2, s_c2, n) == true
        && not_wall_check(s_r, s_c, board) == true
        && not_wall_check(s_r2, s_c2, board) == true) {
        // �κ��� ��� ���� �ִٸ�.
        // �׸��� �ش� ������ ���� �ƴ϶��.
        if (d_map[s_r][s_c][rb.d] == -1 || d_map[s_r2][s_c2][(rb.d + 2) % 4] == -1) {
            // ���� �Ⱥ� �� + �κ������̶��.
            d_map[s_r][s_c][rb.d] = d_map[rb.r][rb.c][rb.d] + 1;
            d_map[s_r2][s_c2][(rb.d + 2) % 4] = d_map[rb.r][rb.c][rb.d] + 1;
            q.push(Robot(s_r, s_c, rb.d));
        }
    }
}
void print_d_map(int n, int mode, vector<vector<vector<int>>>& d_map) {
    cout << "mode :" << mode << "\n";
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d_map[i][j][mode] << " ";
        }
        cout << "\n";
    }
    cout << "------\n\n";
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size() - 1;
    // start point
    // (0,0), (0,1)
    //end point. (n,n)
    //����.
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
    //  �ʱ� �ڵ��� ����.

    q.push(Robot(0, 0, 0)); // 0->
    q.push(Robot(0, 1, 2)); // <-0 ���¸� ����.
    while (!q.empty()) {
        Robot rb = q.front();
        q.pop();
        if ((rb.r == n && rb.c == n) ||
            ((rb.r + dr[rb.d]) == n
                && (rb.c + dr[rb.d]) == n)
            ) {

            break;
        }
        // ã�Ҵ�

        for (int i = 0; i < 4; i++) {
            move_news_robot(rb, i, n, d_map, q, board);
        }
        // �����¿� ���̽�.
        Robot n_rb = Robot(rb.r + dr[rb.d], rb.c + dr[rb.d], (rb.d + 2) % 4);
        spin_robot(rb, +1, n, d_map, q, board);
        spin_robot(rb, -1, n, d_map, q, board);
        spin_robot(n_rb, +1, n, d_map, q, board);
        spin_robot(n_rb, -1, n, d_map, q, board);
        // �κ� �� �ִ� ������ �ð�ݴ� , �ð�.

    }

    for (int i = 0; i < 4; i++)
        print_d_map(n, i, d_map);

    answer = 200000000; // 2��.
    for (int i = 0; i < 4; i++) {
        if (d_map[n][n][i] != -1) {
            if (answer > d_map[n][n][i])
                answer = d_map[n][n][i];
        }
    }
    return answer;
}


int main(void) {
    cout << solution({ {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });
}