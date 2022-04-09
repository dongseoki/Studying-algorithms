# find group that specific element is included in.
def find_parent(parant, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
        return parent[x]
    return x

# union
def union_parent(parent, a,b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else :
        parent[a] = b

# input num of nodes, edges

v, e = map(int, input().split())
parent = [0] * (v+1)
# initialize parent table.

for i in range(1,v+1):
    parent[i] = i

# operate union cal
for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent, a, b)

# print group that each element is included in

print("group that each element is included in")
for i in range(1,v+1):
    print(find_parent(parent, i), end=' ')

print()

# print parent table content
print("부모 테이블:", end=" ")
for i in range(1, v+1):
    print(parent[i], end=" ")