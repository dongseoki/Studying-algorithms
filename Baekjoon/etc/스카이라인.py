# 첫째 줄에 건물의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 N개의 건물에 대한 정보가 주어진다. 건물에 대한 정보는 세 정수 L, H, R로 나타나는데, 각각 건물의 왼쪽 x좌표, 높이, 오른쪽 x좌표를 의미한다. (1 ≤ L < R ≤ 1,000,000,000, 1 ≤ H ≤ 1,000,000,000)

N = int(input())
buildings = []
for _ in range(N):
    lineList = list(map(int, input().split()))
    L = lineList[0]
    H = lineList[1]
    R = lineList[2]
    buildings.append((L,H,R))

# 1 전처리.
buildings.sort()

# 2 계산.


# 3 출력.


# test
# for item in buildings:
#     print(item)