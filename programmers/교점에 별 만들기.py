from itertools import combinations

def solution(line):

    combiCaseList = list(combinations(line, 2))
    pointDict = {}
    for combiCase in combiCaseList:
        # 2개씩 이용해서 교점 유무를 찾아서, pointList에 튜플로 담자..!
        [A,B,E] = combiCase[0]
        [C,D,F] = combiCase[1]
        denominator = (A*D - B*C)
        if  denominator != 0:
            x = (B*F - E * D)/denominator
            y = (E*C - A*F) / denominator

            if float(x).is_integer() and float(y).is_integer():
                pointDict[(int(x),int(y))] = True

    # print(pointList)
        

    # 해당 정보로 그림그리기 시도.
    answer = []
    xLi = []
    yLi = []
    for point in pointDict.keys():
        xLi.append(point[0])
        yLi.append(point[1])
    
    minX = min(xLi)
    maxX = max(xLi)
    minY = min(yLi)
    maxY = max(yLi)

    # 각 점들의 최대 최소 x 및 최대 최소 y값을 찾자.
    for column in range(maxY, minY-1,-1):
        itemStr = ""
        for row in range(minX, maxX+1):
            if (row,column) in pointDict:
                itemStr+="*"
            else:
                itemStr+="."
        answer.append(itemStr)
    # 해당 정보로 적절히 그림을 그리자..!


    return answer

print(solution([[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]))