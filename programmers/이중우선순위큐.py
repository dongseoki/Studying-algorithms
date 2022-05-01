import heapq

class DoublePriorityQueue():
    def __init__(self):
        self.minHeapqList = []
        heapq.heapify(self.minHeapqList)
    
    def insertItem(self, item:int)->None:
        heapq.heappush(self.minHeapqList, item)


    def deleteMinValue(self)->int:
        if self.isQueueEmpty() == False:
            return heapq.heappop(self.minHeapqList)

    def deleteMaxValue(self)->int:
        if self.isQueueEmpty() == False:
            nLargeestList = heapq.nlargest(len(self.minHeapqList), self.minHeapqList)
            value = nLargeestList[0]
            self.minHeapqList = nLargeestList[1:]
            heapq.heapify(self.minHeapqList)
            return value

    def peakMinValue(self):
        if self.isQueueEmpty() == False:
            return self.minHeapqList[0]
    
    def peakMaxValue(self):
        if self.isQueueEmpty() == False:
            return heapq.nlargest(1,self.minHeapqList)[0]

    def isQueueEmpty(self)->bool:
        if len(self.minHeapqList) ==0:
            return True
        else:
            return False

def solution(operations):
    dpq = DoublePriorityQueue()
    answer = []
    for operation in operations:
        opLi = operation.split()
        if opLi[0] == 'I':
            dpq.insertItem(int(opLi[1]))
        else:
            # D 인 경우.
            if int(opLi[1]) ==1:
                # 큐에서 최댓값 삭제.
                dpq.deleteMaxValue()
            else:
                # 큐에서 최솟값 삭제.
                dpq.deleteMinValue()
    
    if dpq.isQueueEmpty() == True:
        return [0,0]
    answer = [dpq.peakMaxValue(), dpq.peakMinValue()]
    return answer

print(solution(["I 16","D 1"]))
print(solution(["I 7","I 5","I -5","D -1"]))
