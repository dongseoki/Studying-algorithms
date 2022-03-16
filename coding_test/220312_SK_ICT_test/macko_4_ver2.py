def get_num_of_node_by_edge(edge):
    if edge in num_of_node_by_edge.keys():
        return num_of_node_by_edge[edge]
    num_of_node_by_edge[edge] = 1 #지금 node를 포함해서 1이됨
    pre_node, node = map(int, edge.split(' '))

    for next_node in linked_node[node]:
        if next_node == pre_node: #왔던 경로로 다시 되돌아 가지 않음
            continue
        next_edge = f'{node} {next_node}'
        num_of_node_by_edge[edge] += get_num_of_node_by_edge(next_edge)

    return num_of_node_by_edge[edge]

def get_edge_case(cmd, edge):
    if edge in dp[cmd].keys():
        return dp[cmd][edge]

    answer = 0
    pre_node, node = map(int, edge.split(' '))

    for next_node in linked_node[node]:
        if next_node == pre_node: #왔던 경로로 다시 되돌아 가지 않음
            continue
        next_edge = f'{node} {next_node}'
        if cmd == 'x': #포함되지 않았으므로 다음번에 j로 선정하거나 않거나
            answer += get_edge_case('x', next_edge)
            answer += get_edge_case('j', next_edge)
        elif cmd == 'j': #j로 포함 하는 것 이라면, 그 아래에 있는 모든 노드의 갯수 만큼 k가 될 수 있다.
            answer += get_num_of_node_by_edge(next_edge)

    dp[cmd][edge] = answer
    return answer


def solution(n, edges):
    answer = 0

    global linked_node
    linked_node = [[] for i in range(n)]

    global dp
    dp = {'x':dict(), 'j':dict()}

    global num_of_node_by_edge
    num_of_node_by_edge = dict()

    for edge in edges:
        linked_node[edge[0]].append(edge[1])
        linked_node[edge[1]].append(edge[0])
    for node in range(n):
        # 여기서 node 가 i 가 된다.
        for next_node in linked_node[node]:
            next_edge = f'{node} {next_node}' #node가 0이고 next_node가 1이라면 '0 1' 엣지가 된다.
            answer += get_edge_case('j', next_edge) #다음 노드를 j로 선정했을때 경우의 수
            answer += get_edge_case('x', next_edge) #다음 노드를 j로 선정하지 않는 경우의 수

    return answer

print(solution(5, [[0, 1], [0, 2], [1, 3], [1, 4]]))
print(solution(4, [[2, 3], [0, 1], [1, 2]]))