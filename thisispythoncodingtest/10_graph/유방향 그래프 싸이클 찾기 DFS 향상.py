from collections import defaultdict
def dfs(here):
    ## 재귀함수 종료 조건
    if visited[here]:
        if visited[here] == -1:
            return True 
        return False # 같지 않다면 사이클을 형성하지 않는 다른 노드에서 온 것이다.


    visited[here] = -1 # DFS 가 안 끝남.
    for nextNode in graph[here]:
        if dfs(nextNode):
            return True

    visited[here] = 1 # DFS가 끝났으니까 1로 설정.
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

    # 모든 정점이 이어져 있다는 가정이다.
    return dfs(2)

print(solution())

# https://hongl.tistory.com/60