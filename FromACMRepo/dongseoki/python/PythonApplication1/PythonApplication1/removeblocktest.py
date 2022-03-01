
sboard = [['C', 'C', 'B', 'D', 'E'], ['*', '*', '*', 'D', 'E'], ['*', '*', '*', 'B', 'F'], ['C', 'C', 'B', 'B', 'F']]
for row in sboard:
  print(row)


m =4
n = 5

def fallingBlocks(m,n,sboard):
    newboard = []
    for i in range(m):
      newboard.append(['*'] * n) 
    for C in range(n):
      RTop = m-1
      for R in range(m-1, -1,-1):
        if sboard[R][C] != '*':
          newboard[RTop][C] =  sboard[R][C]
          RTop -=1
    return newboard

print('')
for row in newboard:
  print(row)