def squareCheck(R,C,m,n,sboard, visited):
  num =0
  if 0<=(R+1)<m and 0<=(C+1)<n:
      if sboard[R][C] == sboard[R+1][C] == sboard[R][C+1] == sboard[R+1][C+1]:
        if visited[R][C] == False:
              visited[R][C] =True
              num +=1
        if visited[R+1][C] == False:
              visited[R+1][C] =True
              num +=1
        if visited[R][C+1] == False:
              visited[R][C+1] =True
              num +=1
        if visited[R+1][C+1] == False:
              visited[R+1][C+1] =True
              num +=1

  return num

def fallingBlocks(m,n,sboard, visited):
    newboard = []
    for i in range(m):
      newboard.append(['*'] * n)
    for C in range(n):
      RTop = m-1
      for R in range(m-1, -1,-1):
        #if sboard[R][C] != '*':
        if visited[R][C] == False:
          # 남아 있는 블록이라면 새로운 보드에 채워주자.
          newboard[RTop][C] =  sboard[R][C]
          RTop -=1
    return newboard
def solution(m, n, board):
    #0.만든다.

    sboard = []
    answer = 0

    for i in range(m):
        sboard.append(list(board[i]))
    #print(sboard)

    print()
    for row in sboard:
      print(row)

    while True:
      removedBlockNum = 0
      visited = []
      for i in range(m):
        visited.append([False] * n)
      for R in range(m):
        for C in range(n):
          if sboard[R][C] !='*':
            removedBlockNum += squareCheck(R,C,m,n,sboard, visited)
            #print(answer)
      #1. 지우기를 시도.(지워질때 마다 answer를 갱신)

      answer += removedBlockNum

      if removedBlockNum != 0:
        # removing blocks.
        sboard = fallingBlocks(m,n,sboard, visited)
        #print('hi')
      else:
        break
      #2. 하나라도 지웠다면 1을 반복.
      # 그렇지 않다면 답을 반환.

    return answer