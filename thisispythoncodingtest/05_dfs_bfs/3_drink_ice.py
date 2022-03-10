n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

# 북서남동
d_r = [-1,0,+1,0]
d_c = [0,-1,0,+1]

def dfs(row, column):
    visited[row][column] = True
    for dir in range(4):
        s_r = row + d_r[dir]
        s_c = column + d_c[dir]
        if 0<=s_r<n and 0<=s_c<m and visited[s_r][s_c]==False and graph[s_r][s_c] == 0:
            dfs(s_r, s_c)



# 1 맵을 만든다.
# 아이스크림 개수를 초기화한다.

# 2 가보지 않은 점을 왼쪽 위부터 오른쪽 아래까지 찾는다.
# 2-1 가보지 않은 점을 찾으면 
#   아이스크림 개수 +1 한다.
#    가봤다 체크를 한다.
#       그 점으로 dfs 탐색을 한다.



# 3 답을 출력한다.


# -----------------------------

# 1 맵을 만든다.
visited = [[False] * m for _ in range(n)]
# 아이스크림 개수를 초기화한다.
ice_count = 0

# 2 가보지 않은 점을 왼쪽 위부터 오른쪽 아래까지 찾는다.
for row in range(n):
    for column in range(m):
        
# 2-1 가보지 않은 점 && 구멍이 뚫려 있다면 
        if visited[row][column] == False and graph[row][column]==0:
#   아이스크림 개수 +1 한다.
            ice_count+=1
#       그 점으로 dfs 탐색을 한다.
            dfs(row, column)

# 3 답을 출력한다.
print('answer = ', ice_count, end=' ')