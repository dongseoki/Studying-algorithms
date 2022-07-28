from typing import Callable
from sys import stdin
import heapq
import bisect


def preload() -> Callable[[], str]:
    data = """8
    1 11 5
    2 6 7
    3 13 9
    12 7 16
    14 3 25
    19 18 22
    23 13 29
    24 4 28
    """

    def make_generator():
        yield from map(str.strip, data.splitlines())

    my_generator = make_generator()

    def my_iterator():
        return next(my_generator)

    return my_iterator


input = stdin.readline
input = preload()


# 이코드는 다른사람에 비해 4배정도 더 걸립니다.
def solve():
    tc = int(input())
    q = []
    for _ in range(tc):
        left, height, right = map(int, input().split())
        heapq.heappush(q, (left, height, 1))
        heapq.heappush(q, (right, height, -1))

    sky = 0
    tree = [0]
    ans = []
    while q:
        item = heapq.heappop(q)

        if item[2] == 1:
            bisect.insort_left(tree, item[1])
        else:
            tmp = bisect.bisect_left(tree, item[1])
            del tree[tmp]

        if q and q[0][0] == item[0]:
            continue

        tmp = tree[-1]
        if tmp != sky:
            sky = tmp
            ans.append([item[0], sky])

    print(" ".join(f"{a} {b}" for a, b in ans))
    # 1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0


if __name__ == "__main__":
    ans = solve()