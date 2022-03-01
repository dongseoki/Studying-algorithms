def solution(S):
    M = len(S[0])
    mapList=[]
#     mapList = [{}] * M
    for i in range(M):
        mapList.append({})
    for (pos,testStr) in enumerate(S):
        listStr = list(testStr)
        for idx in range(M):
            try :
                data = mapList[idx][testStr[idx]]
                return [data, pos, idx]
            except:
                # 데이터가 없음.
                mapList[idx][testStr[idx]] = pos
    return []


print(solution(['gr', 'sd', 'rg']))