# sudo
    # 1 만족하는 블록개수 체크와 떨어지기를 같이함.

    # 삭제했던 블록개수를 answer에 담고

    # 삭제했던 블록개수가 0개가 아니면 1부터 반복.
    # 0이면 break

def deleteMarkingSquare(m,n,sboard,sCMap):
    squareCheckedNum = 0
    newBoard = [['*'] * n for _ in range(m)]
    for C in range(n):
      RTop = m-1
      for R in range(m-1, -1,-1):
        if sCMap[R][C] == False:
            # 남아 있는 블록이라면 새로운 보드에 채워주자.
            newBoard[RTop][C] =  sboard[R][C]
            RTop -=1
        else:
            # 삭제한 블록이면
            squareCheckedNum +=1
    return squareCheckedNum, newBoard


    return squareCheckedNum

def squareCheckandMarking(m,n,sboard,rowNum,colNum,sCMap):
    targetChar = sboard[rowNum][colNum]
    if targetChar == '*':
        return
    if sboard[rowNum+1][colNum] == targetChar and \
        sboard[rowNum][colNum+1] == targetChar and \
        sboard[rowNum+1][colNum+1] == targetChar:
        sCMap[rowNum][colNum] = True
        sCMap[rowNum+1][colNum] = True
        sCMap[rowNum][colNum+1] = True
        sCMap[rowNum+1][colNum+1] = True

def removeBlocks(m,n,sboard):
    sCMap = [[False]*n  for _ in range(m) ]
    for rowNum in range(m-1):
        for colNum in range(n-1):
            squareCheckandMarking(m,n,sboard,rowNum,colNum,sCMap)


    squareCheckedNum, sboard = deleteMarkingSquare(m,n,sboard,sCMap)
    return squareCheckedNum, sboard


def solution(m, n, board):
    answer = 0
    # 초기 설정.삭제 가능한 board 설정.
    sboard = []
    for boardRow in board:
        sboard.append(list(boardRow))
    # 1 만족하는 블록개수 체크와 떨어지기를 같이함.
    while True:
        removedBlockNum, sboard = removeBlocks(m,n,sboard)
        # 삭제했던 블록개수를 answer에 담고
        answer += removedBlockNum

        # 삭제했던 블록개수가 0개가 아니면 1부터 반복.
        # 0이면 break
        if removedBlockNum == 0:
            break

    return answer

solution(4,5,["CCBDE", "AAADE", "AAABF", "CCBBF"])

