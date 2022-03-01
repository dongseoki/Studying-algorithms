def solution(ings, menu, sell):
    answer = 0
    # ings = []
    ingDict = {}

    for data in ings:
        dataList = data.split(" ")
        ingDict[dataList[0]] = int(dataList[1])

    def makeCost(ingsStr, ingDict):
        sum = 0
        for ing in list(ingsStr):
    #         print(ingDict[ing])
            sum += ingDict[ing]
        return sum

    menuDict = {}
    for data in menu:
        dataList = data.split(" ")
        menuDict[dataList[0]]={
            'ingsStr':dataList[1],
            'ingCost':makeCost(dataList[1], ingDict),
            'profit':int(dataList[2])
        }

    answer = 0
    for data in sell:
        dataList = data.split(" ")
        answer += (menuDict[dataList[0]]['profit']-menuDict[dataList[0]]['ingCost']) * int(dataList[1])
    return answer