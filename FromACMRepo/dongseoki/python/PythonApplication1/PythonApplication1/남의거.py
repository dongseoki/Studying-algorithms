
def dfs(depth):
    global n, answer, total_one
 
    # 이미 최소값보다 뎁스가 커지면 더이상 탐색 안하고 리턴
    if answer > 0 and answer <= depth:
        return
 
    # 남은 1이 없을 때 뎁스가 최소값보다 작다면(최초에 answer는 -1)
    if total_one == 0:
        if answer == -1 or answer > depth:
            answer = depth # 값을 할당하고 리턴
        return
 
    # 시작점을 정해야함.
    for y in range(n):
        for x in range(n):
            if MAP[y][x]:
                break
        if MAP[y][x]:
            break
 
    if MAP[y][x]:
        # 해당 점에 1~5 사이즈를 대본다.
        for size in range(1,5+1):
            if paper[size]:
                one2zero = [] # 1 에서 0으로 바뀐 좌표 저장해서 나중에 도로 바꿔준다.
 
                if isCoverable(y,x,size): # 해당 사이즈로 덮을 수 있다면
                    for next_y in range(y,y+size):
                        for next_x in range(x,x+size):
                            MAP[next_y][next_x] = 0 # 1에서 0 으로 바꾸고
                            one2zero.append((next_y,next_x)) # 좌표를 저장
 
                    total_one -= size**(2)
                    paper[size] -= 1
                    dfs(depth+1)
                    paper[size] += 1        # 다시 탐색을 위해 값을 되돌림
                    total_one += size**(2)  # 다시 탐색을 위해 값을 되돌림
 
                    # 바뀐 좌표들을 다시 0에서 1로 바꿔줌
                    for y_x in one2zero:
                        MAP[y_x[0]][y_x[1]] = 1
 
# 색종이로 채울 수 있는지 검사하는 함수
def isCoverable(y,x, size):
    global n
    for _y in range(y, y + size):
        for _x in range(x, x + size):
            if 0 <= _y < n and 0 <= _x < n:
                if MAP[_y][_x] == 0:
                    return False
            else:
                return False
    return True
 
n = 10
MAP = [list(map(int, input().split())) for _ in range(n)]

paper = [0]+[5]*5
answer = -1
total_one = sum(sum(m) for m in MAP)
dfs(0)
print(answer)
