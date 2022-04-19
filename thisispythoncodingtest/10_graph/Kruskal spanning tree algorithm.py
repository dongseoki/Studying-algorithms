# https://www.tutorialspoint.com/data_structures_algorithms/kruskals_spanning_tree_algorithm.htm

# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    # set node as root that is smaller than another
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

# get nums of nodes, nums of edges
v, e = map(int, input().split())
parent = [0] * (v+1) # initialize parent table.

edges = []
result = 0

for i in range(1,v+1):
    parent[i]=i

# 모든 간선에 대한 정보를 입력받기.
for _ in range(e):
    a,b,cost = map(int,input().split())
    edges.append((cost,a,b))

# sort edges by cost asc..
edges.sort()

# check one by one.
for edge in edges:
    cost , a, b = edge
    # include in the graph if there is no cycle.
    if find_parent(parent, a) != find_parent(parent,b):
        union_parent(parent,a,b)
        result += cost

print(result)

