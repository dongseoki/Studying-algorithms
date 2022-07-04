from queue import deque
from queue import Queue
import time


INF = 999999999999
def bfs2(N, M, inputMap):
    disMap = [[[INF, INF] for _ in range(M)] for _ in range(N)]

    #북서남동
    dirRow = [0,-1,0,+1]
    dirCol = [-1,0,+1,0]

    que = Queue()

    # bfs 로 탐색 해보고.
    que.put((0,0,0))
    disMap[0][0][0]=1
    # row, col, 벽 부순 유무. 지금까지 이동한 거리.
    while not que.empty():
        curRow, curCol, curWallCnt = que.get()
        if curRow == N-1 and curCol == M-1:
            return disMap[curRow][curCol][curWallCnt]
        for idx in range(len(dirRow)):
            searRow = dirRow[idx] + curRow
            searCol = dirCol[idx] + curCol
            if 0<=searRow<N and 0<=searCol<M:
                if inputMap[searRow][searCol] == 1 and curWallCnt==0 and disMap[searRow][searCol][1] == INF:
                    # can go.
                    disMap[searRow][searCol][1] = disMap[curRow][curCol][curWallCnt] +1
                    que.put((searRow, searCol, 1))
                elif inputMap[searRow][searCol] == 0 and disMap[searRow][searCol][curWallCnt] == INF:
                    # can go.
                    disMap[searRow][searCol][curWallCnt] = disMap[curRow][curCol][curWallCnt] +1
                    que.put((searRow, searCol, curWallCnt))

    #  제일 끝에 답이 있으면 출력하고, 없으면 -1 출력.
    return -1

def bfs(N, M, inputMap):
    disMap = [[[INF, INF] for _ in range(M)] for _ in range(N)]

    #북서남동
    dirRow = [0,-1,0,+1]
    dirCol = [-1,0,+1,0]

    que = deque()

    # bfs 로 탐색 해보고.
    que.append((0,0,0))
    disMap[0][0][0]=1
    # row, col, 벽 부순 유무. 지금까지 이동한 거리.
    while que:
        curRow, curCol, curWallCnt = que.popleft()
        if curRow == N-1 and curCol == M-1:
            return disMap[curRow][curCol][curWallCnt]
        for idx in range(len(dirCol)):
            searRow = dirRow[idx] + curRow
            searCol = dirCol[idx] + curCol
            if 0<=searRow<N and 0<=searCol<M:
                if inputMap[searRow][searCol] == 1 and curWallCnt==0 and disMap[searRow][searCol][1] == INF:
                    # can go.
                    disMap[searRow][searCol][1] = disMap[curRow][curCol][curWallCnt] +1
                    que.append((searRow, searCol, 1))
                elif inputMap[searRow][searCol] == 0 and disMap[searRow][searCol][curWallCnt] == INF:
                    # can go.
                    disMap[searRow][searCol][curWallCnt] = disMap[curRow][curCol][curWallCnt] +1
                    que.append((searRow, searCol, curWallCnt))

    #  제일 끝에 답이 있으면 출력하고, 없으면 -1 출력.
    return -1

# N, M = map(int, input().split(' '))
# inputMap = []
# for _ in range(N):
#     inputMap.append(list(map(int, list(input()))))

# answer = bfs(N, M, inputMap)
# print(answer)
TEST_SIZE = 64

while TEST_SIZE<3000:
    N = TEST_SIZE
    M = TEST_SIZE
    start = time.time()  # 시작 시간 저장

    inputMap = [[0]* M for _ in range(N)]
    bfs(N, M, inputMap)
    r1 = time.time() - start
    bfs2(N, M, inputMap)
    r2 = time.time() - start
    print(TEST_SIZE, r1, r2)

    TEST_SIZE *=2