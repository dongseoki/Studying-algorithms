def solution(grid, clockwise):
    answer = []
    print(type(clockwise))
    gridMap=[]
    for item in range(len(grid)):
        gridMap.append(['']*(len(grid)*2-1))

    gridMap

    # 데이터 넣기.
    for rowIdx in range(len(grid)):
        arrList=list(grid[rowIdx])
        startIdx= int((len(gridMap[0])-len(arrList))/2)
        for arrIdx in range(len(arrList)):
            gridMap[rowIdx][startIdx+arrIdx]=arrList[arrIdx]



    gridMap

    answer=[]
    if clockwise==True:
        ansList=[]
        answer.append(gridMap[-1][0])

    answer

    lvl =1

    lvl+=1

    # if lvl >len(grid):
    #     break

    hr = len(grid)-1
    hc = 0

    return answer