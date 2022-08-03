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

def solution(play_time, adv_time, logs):
    answer = ''
    endTime = convertToSeconds(play_time)

    # 누적 시간 리스트 초기화1
    cuViewList = [0 for _ in range(endTime +1)]
    for logItem in logs:
        itemStartTime, itemEndTime = logItem.split('-')

        itemStartSeconds = convertToSeconds(itemStartTime)
        itemEndSeconds = convertToSeconds(itemEndTime)
        cuViewList[itemStartSeconds] +=1
        cuViewList[itemEndSeconds] -=1

    # 누적시간 리스트 초기화2
    for idx in range(1,endTime+1):
        cuViewList[idx] = cuViewList[idx] + cuViewList[idx-1]

    acuList = [0 for _ in range(endTime +1)]
    for idx in range(1,endTime+1):
        acuList[idx] = acuList[idx-1] + cuViewList[idx-1]

    maxStartPoint = 0
    maxTime = 0

    adv_seconds = convertToSeconds(adv_time)

    for idx in range(endTime-adv_seconds+1):
        speTime = acuList[idx+adv_seconds]-acuList[idx]
        if speTime > maxTime:
            maxTime = speTime
            maxStartPoint = idx

    return convertToTimeFormat(maxStartPoint)

print(solution("02:03:55","00:14:15",["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))