
import string
from queue import PriorityQueue

def solution(cacheSize, cities):
    answer = 0
    cache = []
    timeList = []
    if cacheSize == 0:
        return len(cities) * 5
    for time in range(len(cities)):
        #print(time)
        item = cities[time].upper()
        if item in cache:
            answer += 1
            # 찾아서 참조시간 갱신하는 코드 필요.
            idx = cache.index(item)
            timeList[idx] = time
            continue
        else :
            answer += 5

        if len(cache) < cacheSize :
           #idx  = len(cache)
           cache.append(item.upper())
           timeList.append(time)
        else :
            mimTime = min(timeList)
            idx = timeList.index(mimTime)

            cache[idx] = item
            timeList[idx] = time
        
    return answer


'''
class CacheDataInfo:
    def __init__(self, time, index):
        self.time = time
        self.index = index
    def __lt__(self, other):
        return self.time < other.time

def solution(cacheSize, cities):
    answer = 0
    que = PriorityQueue()
    cache = []
    for time in range(len(cities)):
        print(time)
        item = cities[time]
        if item.upper() in cache:
            answer += 1
            # 찾아서 참조시간 갱신하는 코드 필요.
            continue
        else :
            answer += 5

        if que.qsize() < cacheSize :
           idx  = len(cache)
           cache.append(item.upper())
           que.put(CacheDataInfo(time, idx))
        else :
            cacheData = que.get()
            cache[cacheData.index] = item
            que.put(CacheDataInfo(time, idx))
        
    return answer'''



#result = solution(3, ['Jeju', 'Pangyo', 'Seoul', 'NewYork', 'LA', 'Jeju', 'Pangyo', 'Seoul', 'NewYork', 'LA'])
result = solution(3, ['Jeju', 'Pangyo', 'Seoul', 'Jeju', 'Pangyo', 'Seoul', 'Jeju', 'Pangyo', 'Seoul'])

print(result)