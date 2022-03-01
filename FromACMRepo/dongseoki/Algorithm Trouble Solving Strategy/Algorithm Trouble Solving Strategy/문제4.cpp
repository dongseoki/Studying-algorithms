#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>

#define F(p,q,r) for(int p =q; p<r;p++)
using namespace std;



void BFS(vector<vector<int>> board, vector<vector<vector<int>>> & memo) {
    queue<pair<pair<int, int>, int>> q;
    F(idx, 0, 4) {
        memo[0][0][idx] = 0;
        q.push(make_pair(make_pair(0, 0), idx));
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> front = q.front();
        q.pop();
        
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<vector<int>>> memo(board.size(), 
        vector<vector<int>>(board[0].size(), 
            vector<int>(4, -1)));


    BFS(board, memo);




    return answer;
}

int main(void) {
    //vector<vector<int>> board = { {0, 0, 0}, { 0,0,0 }, { 0,0,0 } };
    //solution(board);
    char s1[200];
    char s2[20];
    char s3[20];
    char s4[20];
    int a = 0, 
        b = 0;
    //scanf("%s,%s", s1, s1);
    //printf("%s, %s", s1, s2);

    //scanf("%d:%d", &a, &b);
    //printf("%d, %d", a, b);
    scanf("%s", s1);
    char* ptr = strtok(s1, ":");
    char* bptr = ptr;
    printf("출력 시작 \n");
    int i = 0;
    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%d : %s\n",i++, ptr);          // 자른 문자열 출력
        ptr = strtok(NULL, ":");      // 다음 문자열을 잘라서 포인터를 반환
        if (bptr == ptr) {
            printf("그 시기\n");
        }
        bptr = ptr;
    }
}