def solution(s):
    answer = []
    sList =list(s)
    visited = [False] * len(sList)

    def dfs(origin, index,sList,visited):
        total = 1
        leftIdx = (len(sList) + (index-1))%len(sList)
        rightIdx = (len(sList) + (index+1))%len(sList)
        if sList[leftIdx] == origin and visited[leftIdx]==False:
            visited[leftIdx] = True;
            total += dfs(origin, leftIdx,sList,visited)
        if sList[rightIdx] == origin and visited[rightIdx] ==False:
            visited[rightIdx] = True;
            total += dfs(origin, rightIdx,sList,visited)
        return total    

    answer = []
    for index in range(len(sList)):
    #     print(sList[index])
        if(visited[index]==False):
            visited[index] = True;
            origin = sList[index]
            answer.append(dfs(origin, index,sList,visited))
    answer.sort()
    return answer