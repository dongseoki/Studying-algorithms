import re
import copy
from itertools import permutations

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
        if maxValue < result:
            maxValue = result

    # 그중에서 최댓값을 answer에 답는다.
    answer = maxValue

    answer = 0
    return answer

print(solution("100-200*300-500+20"))