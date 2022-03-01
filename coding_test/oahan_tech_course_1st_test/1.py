def solution(arr):
    answer = []
    numCntList = [0] * 4

    for num in arr :
        numCntList[num]+=1
    maxCnt = max(numCntList)
    maxNum = numCntList.index(max(numCntList))
    answer = [maxCnt]*3
    for num in range(1,4):
        if num != maxNum:
            answer[num-1]-= numCntList[num]
        else :
            answer[num-1] = 0
    return answer