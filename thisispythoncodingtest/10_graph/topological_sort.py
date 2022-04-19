from collections import deque

# input nums of nodes and nums of edges
v, e = map(int, input().split())
# initialize 0 for all nodes entry degree.

indegree = [0] * (v+1)
# initialize linked list for saving edges info.
graph = [[] for i in range(v+1)]

# input all edges info for all cycle graph.
for _ in range(e):
    a,b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

# topological sort function
def topology_sort():
    result = [] # list.
    q = deque() # deque library for que.

    # first, insert 0 into node, input degree 0
    for i in range(1, v+1):
        if indegree[i] == 0:
            q.append(i)
    
    # repeat while queue is empty
    while q:
        now = q.popleft()
        result.append(now)

        # subtract 1 from the indegree value of the nodes connected with that element
        for i in graph[now]:
            indegree[i] -=1
            # insert nodes that has indgree value as 0 to queue 
            if indegree[i] == 0:
                q.append(i)
        
    # print result Executing topology sort.
    for i in result:
        print(i, end=' ')

topology_sort()
    

