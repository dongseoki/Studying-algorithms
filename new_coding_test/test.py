# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def binarySearch(target, A):
    low = 0
    high = len(A) - 1
    
    result = False
    while low <= high:
        mid = int((low + high)/2)
        if target > A[mid]:
            low = mid +1
        elif target < A[mid]:
            high = mid -1
        else:
            result = True
            break

    return result

def solution(A):
    # write your code in Python 3.6
    A = sorted(list(set(A)))
    print(A)
    answer = 1
    for target in range(1,1000001):
        if binarySearch(target, A) == False:
            answer = target
            break
    return answer

print(solution([1, 3, 6, 4, 1, 2]))
print(solution([1, 2, 3]))
print(solution([-1, -3]))
