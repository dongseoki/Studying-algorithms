import re
import copy
from itertools import permutations

import operator
opsDict = { "+": operator.add, "-": operator.sub, "*":operator.mul } # etc.

def calculate(numList, operList, operPrioList)->int:
    for tarOper in operPrioList:
        # 연산자 1개 선택.
        # 앞에서 부터 전부 계산.
        operCurIdx = 0
        while operCurIdx<len(operList):
            if tarOper == operList[operCurIdx]:
                calRes = opsDict[tarOper](int(numList[operCurIdx]),int(numList[operCurIdx+1]))
                numList[operCurIdx] = calRes

                # 계산후 해당 피연산자 및 연산자 삭제.
                # 차후 링크드 리스트로 효율화 가능.
                del numList[operCurIdx+1]
                del operList[operCurIdx]


                # 해당 위치부터 다시.
                continue
            operCurIdx +=1

    # 수 1개만 남긴다.
    return abs(numList[0])

def solution(expression):
    # 파싱을 한다.
    # 숫자 리스트.
    numList = re.split('[-+*]', expression)

    # 연산자 리스트.
    operList = []
    for letter in expression:
        if letter in ['+','-','*']:
            operList.append(letter)
    
    # 깊은 복사된 숫자 및 연산자 리스트 와 연산자 우선순위 리스트를 넘기고
    maxValue = -1
    a = ["*","+","-"]
    permute = permutations(a,3)
    for permuteValue in list(permute):
        result = calculate(copy.deepcopy(numList),copy.deepcopy(operList),list(permuteValue))
        # print(list(permuteValue), result)
        if maxValue < result:
            maxValue = result

    # 그중에서 최댓값을 answer에 답는다.
    answer = maxValue
    return answer

print(solution("100-200*300-500+20"))