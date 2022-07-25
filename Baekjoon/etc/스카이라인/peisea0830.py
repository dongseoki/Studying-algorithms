import sys, heapq

# 입력부
n = int(sys.stdin.readline())
arr = []
# arr은 시점 리스트임.

height = [0] * n
# 건물별 높이

q = []
# 라인을 0부터 끝까지 보는데, 이미 지나온 점들의 목록.
# 이것은 힙큐로, 지나온 점들중 가장 높이가 큰것 부터 저장이 되어 있다.
# 특정 노드는, 높이와 끝점의 좌표를 저장함.
# 그리고 q에 있다는 것은 아직 체크 되지 않았다는 의미.

# end : 현재 index번째 건물의 끝나는 지점을 저장하는 리스트
end = [0] * n

# check : 현재까지 끝난 끝점을 저장하는 set
check = set()

for i in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    # 시작점이면 1, 끝점이면 -1
    arr.append((a, i, 1))
    arr.append((c, i, -1))
    height[i] = b
    end[i] = c

# 그림 2, 그림3에 따라 정렬
# 첫번째 우선순위 : 시점이 앞서는지
# 두번째 우선순위 : 시점이 같다면 시작점인지
# 세번째 우선순위 : 시점도 같고 둘 다 시작점이면 높이가 더 높은지
arr.sort(key=lambda x : (x[0], -x[2], -height[x[1]]))

# now : 현재 최고높이
now = 0
ans = []
for i in range(len(arr)):
    # point : 시점, idx : 건물의 인덱스, dir : 시작점인지 끝점인지
    point, idx, dir = arr[i]
    
    # 시작점인 경우(빨간점)
    if dir == 1:
        # 높이가 갱신된다면 그 부분이 새로운 스카이라인
        if now < height[idx]:
            now = height[idx]
            ans.append((point, now))
        # 높이가 갱신됨과 상관없이 현재 건물의 높이와 끝점을 최대 힙에 저장
        heapq.heappush(q, (-height[idx], end[idx]))
        
    # 끝점인 경우(파란점)
    else:
        # 현재 시점이 끝났기 때문에 set에 끝점의 시점을 저장
        check.add(point)
        # 최대 높이가 끝난 건물이 아닐때까지 pop
        while q:
            if q[0][1] not in check:
                break
            heapq.heappop(q)
            
        # 힙이 비었다면 스카이라인의 높이는 0으로 갱신
        if not q:
            if now:
                now = 0
                ans.append((point, now))
                
        # 힙이 있다면 현재 높이와 비교 시 변동이 있다면 그 높이가 그 다음으로 높은 건물이기 때문에
        # 스카이라인 높이 갱신
        else:
            if -q[0][0] != now:
                now = -q[0][0]
                ans.append((point, now))

# 정답 출력
for i in ans:
    print(i[0], i[1], end=' ')