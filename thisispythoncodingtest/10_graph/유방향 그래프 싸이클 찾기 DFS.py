from collections import defaultdict
def dfs(start,here):
    ## 재귀함수 종료 조건
    if visited[here]:
        if start == here: # 시작 정점과 같다면 cycle이다.
            return True 
        return False # 같지 않다면 사이클을 형성하지 않는 다른 노드에서 온 것이다.


    visited[here] = True # 같지 않다면 사이클을 형성하지 않는 다른 노드에서 온것.
    for nextNode in graph[here]:
        if dfs(start, nextNode):
            return True
    return False

def solution():
    N=7
    edges = [(1,2),(1,5), (2,3), (2,6), (3,4), (6,4), (4,7), (7,6)]

    ## 그래프 정보 및 진입 차수 테이블 초기화?
    global graph
    graph = defaultdict(list)
    for edge in edges:
        v, w = edge  # v는 시작점, w는 끝점.
        graph[v].append(w) # w를 v의 이웃에 추가.
    
    global visited
    visited = [0] * (N+1)
    for i in range(1,N+1):
        if dfs(i,i): # 싸이클이 하나라도 존재하면 사이클이 있는 그래프다.
            return True
    return False

print(solution())

        


# https://hongl.tistory.com/60