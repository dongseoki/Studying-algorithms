def convertToSeconds(timeData):
    HH, MM, SS = timeData.split(':')
    return int(HH) * 60 * 60 + int(MM) * 60 + int(SS)

def convertToTimeFormat(secondsData):
    HH = str(secondsData // (60* 60)).zfill(2)
    secondsData -= int(HH) * 60 * 60
    MM = str(secondsData // 60).zfill(2)
    secondsData -= int(MM) * 60
    SS = str(secondsData).zfill(2)
    return HH+':'+MM+':'+SS

def getPointConditionValue(targetSeconds, charData):
    if targetSeconds not in pointDict:
        return 0
    else:
        return pointDict[targetSeconds][charData]

def calculateNewLineCnt(preLineCnt, end_seconds):
    result = 0
    result = preLineCnt + getPointConditionValue(end_seconds-1,'S')\
        -getPointConditionValue(end_seconds-1,'E')
    
    return result

def initMaxReData(play_time, adv_time, logs):
    adv_seconds =  convertToSeconds(adv_time)
    preLineCnt = getPointConditionValue(0,'S')
    result = 0
    for end_seconds in range(1,adv_seconds+1,1):
        newLineCnt = calculateNewLineCnt(preLineCnt, end_seconds)
        result += newLineCnt
        preLineCnt = newLineCnt
        
    return 0, result, adv_seconds, preLineCnt


def initPointDict(logs):
    for logItem in logs:
        itemStartTime, itemEndTime = logItem.split('-')

        itemStartSeconds = convertToSeconds(itemStartTime)
        itemEndSeconds = convertToSeconds(itemEndTime)

        if itemStartSeconds not in pointDict:
            pointDict[itemStartSeconds] = {
                'S':1,
                'E':0
            }
        else:
            pointDict[itemStartSeconds]['S']+=1
        
        if itemEndSeconds not in pointDict:
            pointDict[itemEndSeconds] = {
                'S':0,
                'E':1
            }
        else:
            pointDict[itemEndSeconds]['E']+=1

def calMaxReData(preStartLineCnt, preEndLineCnt, speAcPlStPo, speAcPlEnPo, preAcPlTime):
    speStartLineCnt = calculateNewLineCnt(preStartLineCnt, speAcPlStPo)
    speEndLineCnt = calculateNewLineCnt(preEndLineCnt, speAcPlEnPo)
    result = preAcPlTime - speStartLineCnt + speEndLineCnt
    
    return speStartLineCnt, speEndLineCnt, result

def solution(play_time, adv_time, logs):
    answer = ''
    # maxAcPlStPo
    # maxAcPlTime
    # maxAcPlEnPo

    # 시점관련 데이터 초기화.
    global pointDict
    pointDict = {}
    initPointDict(logs)

    # 최대값들을 초기화.
    maxAcPlStPo,maxAcPlTime,maxAcPlEnPo,preEndLineCnt = initMaxReData(play_time, adv_time, logs)
    
    # 1씩 늘려가면서 계산을 해본다.

    #  초기화.
    speAcPlStPo = maxAcPlStPo + 1
    speAcPlEnPo = maxAcPlEnPo + 1
    speAcPlTime = maxAcPlTime
    endTime = convertToSeconds(play_time)
    preStartLineCnt = 0
    #preEndLineCnt = 

    while speAcPlEnPo <= endTime:
        preStartLineCnt, preEndLineCnt, speAcPlTime= \
            calMaxReData(preStartLineCnt, preEndLineCnt, speAcPlStPo, speAcPlEnPo, speAcPlTime)
        if speAcPlTime >maxAcPlTime:
            maxAcPlStPo = speAcPlStPo
            maxAcPlTime = speAcPlTime
            maxAcPlEnPo = speAcPlEnPo
        speAcPlStPo += 1
        speAcPlEnPo += 1

    return convertToTimeFormat(maxAcPlStPo)

print(solution("02:03:55","00:14:15",["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))