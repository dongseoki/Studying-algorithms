X = int(input())

m1cLi = [0]*(int(X)+1)

m1cLi[1] = 0
for num in range(2,X+1,+1):
    # m1cLi[num] = min of (m1cLi[num//5] +1  , 
    # m1cLi[num//3] +1)
    # m1cLi[num//2] +1
    # m1cLi[num-1] +1 중 최소값.
    # 단 나누어떨어질 경우.
    candiLi =[]
    if num % 5 ==0:
        candiLi.append(m1cLi[num//5]+1)
    if num % 3 ==0:
        candiLi.append(m1cLi[num//3]+1)
    if num % 2 ==0:
        candiLi.append(m1cLi[num//2]+1)
    candiLi.append(m1cLi[num-1]+1)
    m1cLi[num] = min(candiLi)



for num in range(2,X+1,+1):
    print(m1cLi[num], end=' ')
print()
print(m1cLi[X])
