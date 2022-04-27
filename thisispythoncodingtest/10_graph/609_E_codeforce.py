import copy
n, m = map(int,input().split())
# print(n, m)

# initialize edges
edges = []



for _ in range(m):
    u, v, cost = map(int, input().split())
    edges.append((cost,u,v))

# 1 sorting edges

def find_parent(node):
    if parent[node]!=node:
        parent[node] = find_parent(parent[node])
    return parent[node]

def union_parent(a,b):
    a = find_parent(a)
    b = find_parent(b)
    if b > a:
        parent[b] = a
    else:
        parent[a] = b

def kruskal(edges,treeEdgesLi, result):
    edges.sort()
    # one by one, if there is no cycle, merge 
    for (cost,u,v) in edges:
        if find_parent(u) != find_parent(v):
            union_parent(u,v)
            treeEdgesLi.append((cost, u, v))
            result += cost

    # update value of treeEdgesLi 
    for edgeInfo in treeEdgesLi:
        if (edgeInfo not in memoDict) or (memoDict[edgeInfo] > result):
            memoDict[edgeInfo] = result


    return result

global parent
global memoDict
memoDict = {}
for i in range(m):
    # initialize parent 
    if edges[i] not in memoDict:
        parent =[i for i in range(n+1)]
        copied= copy.deepcopy(edges)
        mustContainEdge = copied.pop(i)
        cost,u,v = mustContainEdge
        union_parent(u,v)
        treeEdgesLi = [(cost,u,v)]
        kruskal(copied,treeEdgesLi, cost)
    print(memoDict[edges[i]])

# print(kruskal())
# print(parent)
    
