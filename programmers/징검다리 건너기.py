def isItPossibleCase(stones,k,passCnt) -> bool:
    maxEmptySeriNum = 0
    curEmptySeriNum = 0
    for stoneItem in stones:
        if stoneItem <passCnt:
            curEmptySeriNum += 1
        else:
            if maxEmptySeriNum <curEmptySeriNum:
                maxEmptySeriNum = curEmptySeriNum
            curEmptySeriNum = 0
    if maxEmptySeriNum <curEmptySeriNum:
        maxEmptySeriNum = curEmptySeriNum

    if (maxEmptySeriNum+1) > k:
        return False
    else:
        return True


# def findByBinarySearch(stones, k):
#     low = 0
#     high = 2 * (10 ** 8)
#     while low<=high:
#         mid = int((low+high)/2)
#         T1 = isItPossibleCase(stones,k,mid)
#         T2 = isItPossibleCase(stones,k,mid+1)
#         if T1:
#             if T2==False :
#                 # 특정 구간부터 계속 같은 값이 나온다.
#                 # ex) low=3, high=4
#                 # mid = 3
#                 # 정답은
#                 break
#             else:
#                 low = mid+1
#                 # 정답을 포함하는 상단 범위로 재 탐색.
#         else:
#             high = mid - 1

#     return mid

def findByBinarySearch(stones, k):
    low = 0
    high = 2 * (10 ** 8)
    answer = 0
    while low<=high:
        mid = int((low+high)/2)
        if isItPossibleCase(stones,k,mid):
            low = mid+1
            if answer < mid:
                answer = mid
            # 정답을 포함하는 상단 범위로 재 탐색.
        else:
            high = mid - 1

    return answer

def solution(stones, k):
    answer = 0

    # 이진 탐색에 의한 답 찾기.
    answer = findByBinarySearch(stones, k)

    return answer

print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))
#isItPossibleCase([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3, 6)