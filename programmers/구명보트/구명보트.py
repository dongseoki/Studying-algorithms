from heapq import heappush, heappop

def solution(people, limit):
    answer = 0
    needBoatNum = 0
    people.sort()
    people.reverse()

    maxHeap = []

    heappush(maxHeap, (0, 0))
    # heap을 항상 채우기 위한 조치.

    # 끝에 있는 것부터 하나씩 꺼내서
    # 남은 용량을 max heap에 저장
    # 그러면서 꺼내온것은 남은 힙으로 처리 가능한지 확인하고
    # 가능하면 그 값을 뺏다가 줄여서 다시 넣기
    # 아니면 보트 추가하고, 남은 용량 다시 넣기.
    for maxWeight in people:
        if len(maxHeap) >= 1:
            leftPosWeight = heappop(maxHeap)[1]
            if maxWeight <= leftPosWeight:
                leftPosWeight -= maxWeight
            else:
                needBoatNum += 1
                newLeftPosWeight = limit - maxWeight
                heappush(maxHeap, (-newLeftPosWeight, newLeftPosWeight))
            heappush(maxHeap, (-leftPosWeight, leftPosWeight))



    answer = needBoatNum
    return answer

solution([30, 40, 60, 70], 100)
