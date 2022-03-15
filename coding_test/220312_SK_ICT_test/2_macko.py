# 북서남동
d_r = [-1,0,+1,0]
d_c = [0,-1,0,+1]

NORTH = 0
WEST = 1
SOUTH = 2
EAST = 3



def printArray(array):
    for i in array :
        for j in i:
            print(j,end=" ")
        print()

def move(spIdx, cnt):
    # spIdx - starting position index

    global n
    [row, column, dDir] = pSaveList[spIdx]

    # 다음 방문할점을 방문해본다.
    answer[row][column] = cnt//4 +1
    visited[row][column] = True

    # 방문 예정인 점을 등록한다.
    s_r = row + d_r[dDir]
    s_c = column + d_c[dDir]
    if(visited[s_r][s_c] ==True):
        # 이때 이동 예정인 점이 방문상태면, 방향값을 바꾸고, 바뀐 위치를 등록한다.
        dDir = (dDir + 4 + cDir)%4
        s_r = row + d_r[dDir]
        s_c = column + d_c[dDir]
    pSaveList[spIdx] = [s_r,s_c,dDir]


def solution(n, clockwise):

    global answer
    answer = [[0]* n for _ in range(n)]
    global visited
    visited = [[False]* n for _ in range(n)]

    maxCnt = n*n

    cnt = 0
    # 칠해온 칸의 개수.

    global cDir
    if clockwise ==True:
        cDir = -1
        dDir = EAST # 동
    else :
        cDir = +1
        dDir = SOUTH # 남.

    # 초기 위치 방문 및 숫자 기입
    global pSaveList
    pSaveList = [[0,0,-1],
    [0,n-1,-1],
    [n-1,n-1,-1],
    [n-1,0,-1]]
    # next visited point save list.
    # ex)[[x,y,dirValue], [x,y,dirValue]]

    # 방문 방향 초기화.
    for pSave in pSaveList:
        pSave[2] = dDir
        dDir = (dDir + 4 + -1)%4

    cnt = 0
    while(1):
        if cnt == maxCnt:
            break
        move(cnt%4, cnt)
        cnt +=1

    printArray(answer)        

    # 반환한다. 
    return answer

solution(5,True)
print('\n----\n')
solution(6,False)
print('\n----\n')
solution(9,False)