n = int(input())
data = list(map(int,input().split()))
x = int(input())

sortedData = sorted(data)

# 양 끝을 가리키도록 초기화.
start = 0
end = len(sortedData)-1
count = 0
while start <end:
    twoNumSum = sortedData[start] + sortedData[end]
    if twoNumSum <x:
        start+=1
    else:
        # twoNumSum >=x
        if twoNumSum ==x:
            count +=1
        end -=1
print(count)