from queue import Queue


INF = 999999999999

N, M = map(int, input().split(' '))
inputMap = []
for _ in range(N):
    inputMap.append(list(map(int, list(input()))))

disMap = [list([INF, INF] for _ in range(M)) for _ in range(N)]

#북서남동
dirRow = [0,-1,0,+1]
dirCol = [-1,0,+1,0]


que = Queue()

# bfs 로 탐색 해보고.
que.put((0,0,0, 1))
disMap[0][0][0]=1
# row, col, 벽 부순 유무. 지금까지 이동한 거리.
while not que.empty():
    curRow, curCol, curWallCnt, curDis = que.get()
    for idx in range(len(dirRow)):
        searRow = dirRow[idx] + curRow
        searCol = dirCol[idx] + curCol
        if 0<=searRow<N and 0<=searCol<M:
            if inputMap[searRow][searCol] == 1 and curWallCnt==0 \
                and disMap[searRow][searCol][1] > (curDis+1):
                # can go.
                disMap[searRow][searCol][1] = curDis+1
                que.put((searRow, searCol, 1,curDis+1))
            elif inputMap[searRow][searCol] == 0 and disMap[searRow][searCol][0] > (curDis+1):
                # can go.
                disMap[searRow][searCol][0] = curDis+1
                que.put((searRow, searCol, curWallCnt,curDis+1))



#  제일 끝에 답이 있으면 출력하고, 없으면 -1 출력.
answer = min(disMap[N-1][M-1])
if answer == INF:
    print(-1)
else:
    print(answer)