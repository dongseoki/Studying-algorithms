
DEVNUM = 10000019

def caseOfRouteStoE(sT,eT):
    width = eT[0]-sT[0]
    height = eT[1]-sT[1]
    return combiLi[width+height][width]


def caseOfRouteByDirectEdge(dirDiag, width, height):
    ep = dirDiag[0]
    lp = dirDiag[1]

    return (caseOfRouteStoE((0,0), ep) * caseOfRouteStoE(lp,( width, height))) % DEVNUM

def solution(width, height, diagonals):

    answer = 0

    # 격자에 해당하는 경로의 개수를 모두 구해서 저장해둔다.
    global combiLi
    combiLi = [[1]* 251 for _ in range(251)]
    for n in range(1,251,+1):
        for c in range(n):
            if c== 0 or c== n:
                continue
            combiLi[n][c] = (combiLi[n-1][c-1] + combiLi[n-1][c])% DEVNUM


    # 대각선리스트를 순회한다.
        # 하나를 빼고
        # 하나를 이용한 모든 케이스(AB, BA 로이어지는 경로)를 계산해 answer 에 더한다.
        # 더하거나 곱할때는 모드 연산을 이용한다.
    for diag in diagonals:
        dirDiag = [(diag[0]-1,diag[1]),(diag[0],diag[1]-1)]
        answer = (answer + caseOfRouteByDirectEdge(dirDiag, width, height) 
        + caseOfRouteByDirectEdge(list(reversed(dirDiag)), width, height))% DEVNUM


    return answer

print(solution(2,2,[[1,1],[2,2]]))

print(solution(51,37,[[17,19]]))