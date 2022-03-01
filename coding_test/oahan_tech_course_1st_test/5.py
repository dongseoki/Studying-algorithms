def solution(rows, columns):
    answer = [[]]

    gridMap=[]

    for item in range(rows):
        gridMap.append([0]*columns)

    # 1현재 위치를 1행 1열로 정하고, 그 위치에 숫자 1을 씁니다.
    zeroCount = rows * columns
    r =0
    c =0
    gridMap[0][0]= 1
    recent = gridMap[0][0]
    zeroCount-=1
    while(True):
        # print(gridMap)
        # 2 r을 현재 위치의 행, c를 현재 위치의 열로 정의합니다.
        # 3 만약 격자 내에 0이 쓰인 칸이 없거나, 더 이상 0이 쓰여 있는 칸에 다른 숫자를 쓸 수 없게 된다면 과정을 즉시 종료합니다.
        if zeroCount==0:
            break

        # 4 만약 가장 최근에 쓴 숫자가 짝수라면, r행 c열에서 r+1행 c열로 이동합니다. r = rows라면, 1행으로 이동합니다.
        if(recent%2 ==0):
            r= (rows+r+1)%rows
        # 5 만약 가장 최근에 쓴 숫자가 홀수라면, r행 c열에서 r행 c+1열로 이동합니다. c = columns라면, 1열로 이동합니다.
        else :
            c= (columns+c+1)%columns

        if gridMap[r][c] ==0:
            zeroCount-=1
        else:
    #         이미 쓰여져 있는 숫자가, 쓰려고하는 숫자와(최근에 쓴 숫자+1)와 속성이 같다면(홀이였는데, 홀)
            if (recent+1-gridMap[r][c])%2 ==0:
                break
        # 6 도착한 칸에 원래 쓰여 있던 수를 지우고 가장 최근에 쓴 숫자 + 1을 씁니다.
        gridMap[r][c]=recent +1
        recent=gridMap[r][c]
        # 7 2번 과정으로 돌아갑니다.
    answer = gridMap
    return answer