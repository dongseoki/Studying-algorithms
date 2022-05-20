N = int(input())
dataList = list(map(int, input().split()))

M = int(input())
targetList = list(map(int, input().split()))

# 정렬
dataList.sort()

def binary_search(dataList, target):
    low = 0
    high = len(dataList)-1

    while low<=high:
        mid = int((low + high)/2)
        if dataList[mid] == target:
            return 1
        elif dataList[mid] > target:
            high = mid -1
        else:
            # <
            low = mid +1
    return 0


# 한개씩 타겟이 있는지 확인후, 있으면 1, 없으면 0
for target in targetList:
    print(binary_search(dataList, target))