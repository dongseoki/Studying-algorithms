def is_it_available(i,j,num, paperMap):
    flag = True
    for R in range(i,i+num,+1):
        for C in range (j, j+num, +1):
            if paperMap[R][C] != 1:
                return False
    return True

def process_paper(i, j, num, value, paperMap):
    for R in range(i,i+num,+1):
        for C in range (j, j+num, +1):
            paperMap[R][C] = value

def try_one_dfs_paper_paste(R, C,num, paperMap):
    if (R+num -1)< 10 and (C+num-1)<10:
        if is_it_available(R,C,num, paperMap) == True :
            return True, R,C
    return False, -1, -1

def dfs(picked_num,paperCountList, oneCount, paperMap):
    global ans
    if ans < picked_num:
        return
    if oneCount <=0 :
        if ans > picked_num :
            ans = picked_num
        return
    for R in range(n):
        for C in range(n):
            if paperMap[R][C]:
                break
        if paperMap[R][C]:
            break
    
    for num in range(5,0,-1):
        if paperCountList[num]<=0:
            continue
        flag, x, y =try_one_dfs_paper_paste( R,C,num,paperMap)
        if(flag == True):
            # 여기서 DFS.
            process_paper(x,y,num,0, paperMap)
            paperCountList[num] -= 1
            dfs(picked_num+1, paperCountList, oneCount - num **2, paperMap)
            paperCountList[num] += 1
            process_paper(x,y,num,1, paperMap)
    return 

n=10
paperMap = [list(map(int, input().split())) for _ in range(n)]
#print(paperMap)

# 5짜리 부터 보기.
ans = 50
oneCount =0
for i in range(10):
    for j in range(10):
        if paperMap[i][j] == 1:
            oneCount+=1

paperCountList = [0,5,5,5,5,5]


sumExe = sum(sum(m) for m in paperMap)

dfs(0,paperCountList,oneCount, paperMap)

if ans != 50 :
    print(ans)
else :
    print(-1)