
def solution(array, commands):
    answer = []
    for command in commands:
        start = command[0]
        end = command[1]
        k = command[2]
        cutList = array[start-1:end]
        cutList.sort()
        answer.append(cutList[k-1])
    return answer

result = solution([1, 5, 2, 6, 3, 7, 4]	,[[2, 5, 3], [4, 4, 1], [1, 7, 3]])
print(result)


(list(sorted(array[i-1:j]))[k-1])