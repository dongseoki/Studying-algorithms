def findTopRoot(skills):
    li  = [i*0 for i in range(len(skills)+2)]
    li[0] = -1
    for item in skills : 
        li[item[1]] = item[0]
    topRootNum = li.index(0)
    return topRootNum

def dfs(skidx, adjList, ratioList):
    if len(adjList[skidx]) == 0:
        ratioList[skidx] = 1
        return ratioList[skidx]
    else :       
        for item  in adjList[skidx]:
            ratioList[skidx] += dfs(item, adjList, ratioList)
        return ratioList[skidx]

def makeAdjList(skills):
    adjList = []
    for i in range(len(skills)+2):
        adjList.append([])
    for item in skills : 
        adjList[item[0]].append(item[1])
    return adjList


def solution(total_sp, skills):
    answer = []
    
    topRootNum = findTopRoot(skills)
    # 1. 최상위 루트 찾기
    
    adjList = makeAdjList(skills)
    # 2-1 dfs 환경 구축. 인접 리스트
    
    ratioList =[ 0 for i in range(len(adjList))]
    dfs(topRootNum, adjList,ratioList)
    # 2. dfs 하기. 그결과를 ratioList에 저장하기.
    
    minimum_sp = int(total_sp / sum(ratioList))
    # 3. minimum_sp  = total_sp / (ratio List 값의 합)
    
    for idx in range (1,len(skills) +2):
        answer.append(minimum_sp * ratioList[idx])
    # 4. minimum_sp * ratioLIst 각각 해두기.
    return answer

total_sp = 121
skills =[[1, 2], [1, 3], [3, 6], [3, 4], [3, 5]]

print(solution(total_sp, skills))