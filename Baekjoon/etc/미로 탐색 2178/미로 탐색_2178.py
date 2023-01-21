from collections import deque

dRow = [+1,-1,0,0]
dCol = [0,0,+1,-1]

def bfs(mazeMap):
    answer = 0
    visited = [[False] * len(mazeMap[0]) for _ in range(len(mazeMap))]
    queue = deque()
    queue.append((0,0,1)) # rowNum, colNum, minDistanceFrom(0,0)
    visited[0][0]=True
    while len(queue)>0:
        row, col, curDistance =queue.popleft()
        if row == len(mazeMap)-1 and col == len(mazeMap[0])-1:
            answer = curDistance
            break
        for dir in range(0,len(dRow)):
            searchRow = row + dRow[dir]
            searchCol = col + dCol[dir]
            if 0<= searchRow < len(mazeMap) \
            and 0<=searchCol < len(mazeMap[0])\
            and visited[searchRow][searchCol]==False\
            and mazeMap[searchRow][searchCol]==1:
                queue.append((searchRow, searchCol, curDistance+1))
                visited[searchRow][searchCol] = True
    return answer    


[N,M ]= map(int, input().split(' '))
mazeMap = []
for _ in range(N):
    mazeMap.append(list(map(int,list(input()))))

answer = bfs(mazeMap)
print(answer)