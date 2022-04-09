# set INF as 1bilion
from ast import Try


INF = int(1e9)

# input num of nodes, num of edges
n = int(input())
m = int(input())

# make  2dim list, make all value INF
graph = [[INF] * (n+1) for _ in range(n+1)]

# cost that it goes to itself initialize as 0
for row in range(1,n+1):
    for col in range(1,n+1):
        if row==col:
            graph[row][col] = 0

# input info about each edge, and intialize that value.
for _ in range(m):
    # form A to B, cost C.
    a, b, c  = map(int, input().split())
    graph[a][b] = c

# do 플로이드 워셜 알고리즘 by 점화식.
for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            try :
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])
            except :
                print('hi I')
# print result
for a in range(1,n+1):
    for b in range(1, n+1):
        # if can not go, print INFINITY
        if graph[a][b] == INF:
            print('INF', end=" ")
        else:
            print(graph[a][b], end=" ")
    print()