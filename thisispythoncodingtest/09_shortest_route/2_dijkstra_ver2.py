import sys
import heapq
import numpy as np
input = sys.stdin.readline

# 10억 설정하기.
INF = int(1e9)

# input numbers of node, edge
n, m = map(int, input().split())

# input number of first node.
start = int(input())

# input infos of edges, a->b, cost c
## initialization
graph = [[] for i in range(n+1)]
## input infos
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b,c))

# initialization of distance table.
distance = [INF] * (n+1)


#numpy를 이용한 예.
# 불가능 함을 깨달음. visited를 고려 못했었다.
# def get_smallest_node2():
#     # 1번 인덱스 부터 끝까지중 가장 작은 값의 인덱스 얻기.
#     index_min = np.argmin(distance[1:])

#     # 앞에서 0번을 잘랐어서... 1을 더해야한다.!
#     return index_min+1

# define dijkstra
def dijkstra(start):
    # initialization about start point
    q = []

    heapq.heappush(q,(0,start))
    distance[start] = 0

    while q:
        # get node number which has a shortest value
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        # check nodes which is connected current node(now)
        for (tNode, weight) in graph[now]:
            cost = distance[now] + weight
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[tNode]:
                distance[tNode] = cost
                heapq.heappush(q, (cost, tNode))
        



# executed 다익스트라
dijkstra(start)

# display all node from start point .
for i in range(1,n+1):
    # If there are no routes from start to target node(i), print infinity..
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])