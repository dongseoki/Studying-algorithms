# input num of nodes, edges

N, M = map(int, input().split())

parent = [i for i in range(N+1)]
# 자기 자신을 루트로 초기화.

def find_parent(node):
    if parent[node]!= node:
        parent[node] = find_parent(parent[node])
    return parent[node]

def merge(a,b):
    a = find_parent(a)
    b = find_parent(b)
    if a<b:
        parent[b] = a
    else :
        parent[a] = b


def isItOnSameSide(a,b):
    return find_parent(a) == find_parent(b)

for _ in range(M):
    t, a, b = map(int, input().split())
    if t ==0:
        # 합치기.
        merge(a,b)
        pass
    elif t==1:
        # 같은 팀 여부 확인.
        print(isItOnSameSide(a,b))