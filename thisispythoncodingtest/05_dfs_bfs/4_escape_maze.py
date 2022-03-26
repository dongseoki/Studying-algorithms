from collections import deque


# 5 6
# 101010
# 111111
# 000001
# 111111
# 111111

# 북서남동
d_r = [-1,0,+1,0]
d_c = [0,-1,0,+1]

def bfs():
    queue = deque([])
    queue.append((0,0))
    while len(queue) >0:
        (row, column) = queue.pop()
        for dir in range(4):
            s_r = row + d_r[dir]
            s_c = column + d_c[dir]
            # 범위 내 좌표고, 괴물 없고, 이미 간적도 없을때
            if 0<=s_r<n and 0<=s_c<m and mazeLi[s_r][s_c] == 1 and memo[s_r][s_c]==-1:
                memo[s_r][s_c] = memo[row][column]+1
                queue.append((s_r,s_c))
                
                

def solution():
    global n
    global m
    n, m = map(int, input().split(' '))
    global mazeLi
    mazeLi = []
    for _ in range(n):
        mazeLi.append(list(map(int,input())))
    global memo
    memo = [[-1] * m for _ in range(n)]

    # 초기화
    memo[0][0]=1


    # 미로 탐색 BFS
    bfs()

    # 정답 반환.
    return memo[n-1][m-1]


print(solution())
