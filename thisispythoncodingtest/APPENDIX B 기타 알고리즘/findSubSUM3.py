n = 5 # 데이터 개수
m = 5 # 찾고자 하는 부분합 M
data = [1,2,3,2,5]

# 리스트인 data가 위처럼 주어지고, n개의 데이터일때
# m 의 부분합의 개수를 구하여라(단, 부분합이란 인접원소들의 수의 합을 일 컫는다.)

count = 0
interval_sum = 0
# interval_sum은 현재 start 이상, end 미만인 인덱스를 갖는 원소들의 합이다.
start = 0
end = 0

# 초기화


# 아래 있는 것들을 모두 볼때 까지 해본다.

# 현재 부분합이 목표보다 작으면
# end를 증가시킨다.

# 목표보다 크거나 같으면
## 목표와 같다면 일단 카운트한다.
## start를 1증가시킨다.

while start<=end and start >=0:
    if interval_sum >= m:
        if interval_sum == m:
            count +=1
        
        interval_sum -= data[start]
        start +=1
    else:
        if end<len(data):
            end +=1
            interval_sum += data[end-1]
        else:
            break





print(count)

