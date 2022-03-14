import itertools

juList=[1,5,10,50,100,500]

# costsList = []

def calculate(money, ip):
    result = -1

    makeBillCost = 0
    # 들어온 값 순서대로 최대한 채움. greedy하게 채움.
    for index in ip:
        # 남은 생산 가치내에서 가용한 동전 개수를 계산하고.
        # money // juList[index]

        # 생산 비용 더하고
        makeBillCost += money // juList[index] * costsList[index]

        # 생산 가치를 그만큼 차감한다.
        money = money % juList[index]


    # 만약 생산화폐가치를 만족시킬수 있다면(남은돈이 0),
    if money == 0 :
        # 생산 비용을 반환함.
        return makeBillCost
    else:
        return -1


def solution(money, costs):
    global costsList
    costsList = costs
    answer = 999999

#   test
    # y = [i for i in range(3)] # [0, 1, 2]
    # c_permuatation = itertools.permutations(y, 3)
    # for yp in y_permuatation:
    #     print(yp)

    y = [i for i in range(6)] # [0, 1, 2,3,4,5]
    i_permuatation = itertools.permutations(y, len(y))
    # costs를 6!로 섞어서 뽑는다.
    for ip in i_permuatation:
        # print(yp)
            # 계산을 해보고
        # 오 되네..?
        result = calculate(money, ip)
        if result != -1 and result<answer:
        # 그 값이 asnwer보다 작으면 answer로 저장.
            answer = result
    return answer

money = 4578
costs = [1, 4, 99, 35, 50, 1000]	


print(solution(money, costs))