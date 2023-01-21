from collections import defaultdict
def solution(k, tangerine):
    answer = 0
    tanDict = defaultdict(int) # key : size . value : cntOfSameSizeTagerine.
    for item in tangerine:
        tanDict[item]+=1
    tanCntList = list(tanDict.values())
    tanCntList.sort(reverse=True)
    includedItemCnt=0
    for (idx, itemCntWithSameSize) in enumerate(tanCntList):
        if includedItemCnt + itemCntWithSameSize <k:
            includedItemCnt+=itemCntWithSameSize
        else:
            answer = idx+1
            break
    return answer

print(solution(6, [1, 3, 2, 5, 4, 5, 2, 3]))