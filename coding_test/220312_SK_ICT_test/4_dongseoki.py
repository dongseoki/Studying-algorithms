

# x-y의 간선의 반대방향으로, y로부터 시작해서 갈수 있는 모든 점 중에서 j와 k가 될수있는 경우의 수.
# (y를 j로 선택했을 경우)
#  y-w의 간선의 반대방향으로, w로부터 시작해서 갈수 있는 모든 점의 개수(즉 가능한 모든 K의 개수.)
# 더하기.
# (y를 j로 선택하지 않은 경우)
# j가 y가 아니면서, y로갈수 있는 모든 점의 목록이 (x, 알파, 베타 라고 했을때) x를 제외한 점들을 w라 가정하고.
#  y-w의 간선의 반대방향으로, w로부터 시작해서 갈수 있는 모든 점 중에서 j와 k가 될수있는 경우의 수.

# getJK및 getK는 DP를 이용해서 미리 저장해두도록 하자..!!

# x-y의 간선의 반대방향으로, y로부터 갈수 있는 y를 포함한 모든 점의 개수
# 1
# 더하기
#  y로갈수 있는 모든 점의 목록이 (x, 알파, 베타 라고 했을때) x를 제외한 점중에 하나를 w라 가정하고.
#  y-w의 간선의 반대방향으로, w로부터 시작해서 갈수 있는 모든 점의 개수.
# 탈출조건은 더이상 갈수 없는 경우

# 결론.
# getJK([soe,eoe]) :  soe-eoe의 간선의 반대방향으로, eoe로부터 시작해서 갈수 있는 모든 점 중에서 j와 k가 될수있는 경우의 수
# getK([soe,eoe]) : soe-eoe의 간선의 반대방향으로,  eoe로부터 시작해서 갈수 있는 모든 점의 개수.

# getJK([soe,eoe]) = All (getK([eoe,w]) + getJK([eoe,w])) ( w는 eoe점에 연결된 soe가 아닌 모든 점.)
# getK([soe,eoe]) = 1 + All getK([eoe,w]) (w는 eoe점에 연결된 soe가 아닌 모든 점.)

# 단계적 개발 방향 
# 1 DP 없이 개발..!
# 2 DP를 적용..!


# dirEdge : direction Edge.
# soe : start of Edge.
# eoe : end of Edge.

def getK(dirEdge):
# getK([soe,eoe]) = 1 + All getK([eoe,w]) (w는 eoe점에 연결된 soe가 아닌 모든 점.)
    soe = dirEdge[0]
    eoe = dirEdge[1]

    if (soe, eoe) in getKDpDict:
        return getKDpDict[(soe, eoe)]

    sum = 1
    for w in adjLi[eoe]:
        if w == soe:
            continue
        sum += getK([eoe,w])
    
    getKDpDict[(soe, eoe)] = sum
    return sum

def getJK(dirEdge):
# getJK([soe,eoe]) = All (getK([eoe,w]) + getJK([eoe,w])) ( w는 eoe점에 연결된 soe가 아닌 모든 점.)
    soe = dirEdge[0]
    eoe = dirEdge[1]

    if (soe, eoe) in getJKDpDict:
        return getJKDpDict[(soe, eoe)]

    sum = 0
    for w in adjLi[eoe]:
        if w == soe:
            continue
        sum += getK([eoe,w]) + getJK([eoe,w])

    getJKDpDict[(soe, eoe)] = sum
    return sum

def solution(n, edges):
    answer = 0

    # DP 용.ㅣ
    global getJKDpDict
    getJKDpDict = {}
    # key : tuple. (int,int)
    # value : int

    global getKDpDict
    getKDpDict = {}
    # key : tuple. (int,int)
    # value : int


    # 연결리스트를 만들자.
    global adjLi
    adjLi = [[] for i in range(n)]

    for edge in edges:
        adjLi[edge[0]].append(edge[1])
        adjLi[edge[1]].append(edge[0])
        # 양 방향 연결.

    # 2 
    # i를 모든 점으로 가정하자.
    for i in range(n):
    # i를 하나씩 꺼내서.
        for nextEdge in adjLi[i]:
    # i에 연결된 점들을 이용해 getJK의 결과를 answer에 더한다..!
            answer += getJK([i,nextEdge])
    return answer

print(solution(5, [[0,1],[0,2],[1,3],[1,4]]))

print(solution(4, [[2,3],[0,1],[1,2]]))