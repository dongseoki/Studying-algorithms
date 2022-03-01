# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
    if N >100000000:
        return -1
    testList = list(str(N))
    testList.sort(reverse=True)
    data =int(''.join(testList))
    if data > 100000000:
        return -1
    
    return data