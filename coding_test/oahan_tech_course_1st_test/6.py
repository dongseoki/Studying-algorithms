def makeHH(time12):
    if time12[-2]=='P':
        return int(time12[:-2])+ 12
    else : 
        return int(time12[:-2])

FwayToWork = 9.5
FoffWork = makeHH("6PM")
MwayToWork = makeHH("1PM")
MoffWork = makeHH("6PM")

def makeCostTime(plan):
    total =0
    startTime = makeHH(plan[1])
    # 금요일 계산.
    if startTime< FoffWork : 
        total += FoffWork-startTime
        if startTime < FwayToWork:
            total -= FwayToWork-total
    
    endTime = makeHH(plan[2])
    
    # 월요일 계산.
    if endTime > MwayToWork:
        total+= endTime-MwayToWork
        if endTime > MoffWork:
            total-=endTime-MoffWork
    return total

def solution(time, plans):
    answer = ''
    remainTime=time
    travelList=[]
    for plan in plans:
        costTime = makeCostTime(plan)
        if remainTime <costTime:
            break
        else:
            remainTime-=costTime
            travelList.append(plan[0])
    answer= travelList[-1]
    return answer



solution(3.5,[ ["홍콩", "11PM", "9AM"], ["엘에이", "3PM", "2PM"] ])