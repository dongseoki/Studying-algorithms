def get_edge_case(contain_j, edge):
    if edge in dp[contain_j].keys():
        print('dp lookup occured')
        return dp[contain_j][edge]
    dp[contain_j][edge] = 0

    pre_node, node = map(int, edge.split(' '))

    for next_node in linked_node[node]:
        if next_node == pre_node: #왔던 경로로 다시 되돌아 가지 않음
            continue
        next_edge = f'{node} {next_node}'

        dp[contain_j][edge] += get_edge_case(0, next_edge)# 다음으로 가는 edge의 k가 될 수있는 모든 노드의 수
        if contain_j==1: #해당 노드를 j로 할 수 있지만 하지 않고 다음 노드로 넘길때 경우의수
            dp[contain_j][edge] += get_edge_case(1, next_edge)

    if contain_j == 0: #j가 아니라는 것은 k 값이 될 수 있는 경우 이므로 1개를 더해준다.
        dp[contain_j][edge] += 1

    return dp[contain_j][edge]
    # contain_j 가 1이면


def solution(n, edges):
    answer = 0

    global linked_node
    linked_node = [[] for i in range(n)]

    global dp
    dp = [dict(), dict()]  # dp[0]은 j를 포함하지 않음, dp[1]은 j를 포함

    for edge in edges:
        linked_node[edge[0]].append(edge[1])
        linked_node[edge[1]].append(edge[0])
    for node in range(n):
        for next_node in linked_node[node]:
            next_edge = f'{node} {next_node}'
            answer += get_edge_case(1, next_edge) #j를 포함시키거나 시키지 않는 경우의 수
    return answer

print(solution(5, [[0, 1], [0, 2], [1, 3], [1, 4]]))
print(solution(4, [[2, 3], [0, 1], [1, 2]]))