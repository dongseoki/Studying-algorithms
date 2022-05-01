n = 5 # 데이터 개수
m = 5 # 찾고자 하는 부분합 M
data = [1,2,3,2,5]

count = 0
interval_sum = 0
end = 0

# 1 시작점과 끝점이 첫번째 인덱스를 가리키도록 한다.
# 2 현재 부분합이 M과 같다면 카운트 한다.
# 3 현재 부분합이 M 보다 작으면 end를 1 증가시킨다.
# 4 현재 부분합이 M보다 크거나 같으면 start를 1증가시킨다.
# 5 모든 경우를 확인할 때까지 2~4번 까지의 과정을 반복한다.


# start 증가시키며 반복.
for start in range(n):
    # end를 가능한 만큼 이동시키기.
    # 3 현재 부분합이 M 보다 작으면 end를 1 증가시킨다.
    while interval_sum < m and end < n:

        interval_sum += data[end]
        end +=1
    # 2 현재 부분합이 M과 같다면 카운트 한다.
    if interval_sum == m:
        count +=1
    # 4 현재 부분합이 M보다 크거나 같으면 start를 1증가시킨다.
    interval_sum -= data[start]


print(count)