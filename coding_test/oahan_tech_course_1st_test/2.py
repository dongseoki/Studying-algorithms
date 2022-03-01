def solution(log):
    answer = ''
    estStudyTimeList = []
    realStudyTimeList = []
    answer = ""

    def makeMinuteTime(timeStr) :
        timeList = timeStr.split(":")
        return int(timeList[0]) * 60 + int(timeList[1])

    while len(log)>=2:
        endTime = log.pop()
        startTime = log.pop()
        estStudyTimeList.append(makeMinuteTime(endTime) - makeMinuteTime(startTime))


    for estTime in estStudyTimeList:
        realTime = 0
        if estTime <5:
            realTime = 0
        elif estTime >=105:
            realTime = 105
        else:
            realTime = estTime
        realStudyTimeList.append(realTime)

    totalTime = 0
    for realTime in realStudyTimeList:
        totalTime += realTime

    answer = str(int(totalTime/60)).zfill(2) + ":"+str(totalTime%60).zfill(2)
    return answer