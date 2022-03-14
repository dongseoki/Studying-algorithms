
# 북서남동


d_r = [-1,0,+1,0]
d_c = [0,-1,0,+1]
# NWSE

maxCnt = -1
NORTH = 0
WEST = 1
SOUTH = 2
EAST = 3

def calLeftDis(row,column, dDir,n, wave):
    # 동쪽 일 경우.
    if (dDir == EAST):
        return n-wave-column
    if (dDir == WEST):
        return column - wave +1
    if (dDir == SOUTH):
        return n-wave-row
        # return row-wave +1
    if (dDir == NORTH):
        return row-wave +1
        # return n-wave-row

def printArray(array):
    for i in array :
        for j in i:
            print(j,end=" ")
        print()

def draw(row,column, dDir,cDir,answer,n):
    global maxCnt
    leftDis = n-1
    count = 1
    wave = 1

    # 초기 설정.
    answer[row][column] = count
    count +=1

    # 전략
    # 이동해서.
    # 표기한다.
    while True:
        leftDis = calLeftDis(row,column, dDir,n, wave)
        if leftDis <=0:
            break


        for do in range(leftDis-1):
            row = row + d_r[dDir]
            column = column + d_c[dDir]
            try:
                answer[row][column] = count
                if count > maxCnt:
                    maxCnt = count
            except:
                print('error', row, column, leftDis, do)
            count +=1
        dDir = (dDir+cDir+4) %4
        wave +=1


def solution(n, clockwise):
    global maxCnt
    answer = [[0]* n for _ in range(n)]

    # clockwise 가 참일때
    # cDir = -1로

    # clockwise가 거짓일때
    # cDir = +1로
    if clockwise ==True:
        cDir = -1
        dDir = EAST # 동
    else :
        cDir = +1
        dDir = SOUTH # 남.

    # 4군데를 하나씩 해본다.
    draw(0,0, dDir,cDir,answer,n)

    dDir = (dDir-1+4) %4
    draw(0,n-1, dDir,cDir,answer,n)

    dDir = (dDir-1+4) %4
    draw(n-1,n-1, dDir,cDir,answer,n)

    dDir = (dDir-1+4) %4
    draw(n-1,0, dDir,cDir,answer,n)

    # n이 홀수일경우 가운데 숫자 계산.
    if (n+1) %2 == 0:
        answer[n//2][n//2] = maxCnt + 1

    # test 출력
    # printArray(answer)

    # 반환한다. 
    return answer


solution(5,True)
print('\n----\n')
solution(6,False)
print('\n----\n')
solution(9,False)