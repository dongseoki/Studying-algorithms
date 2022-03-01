
def solution(n):
    answer = 0
    value = n
    b = format(value, 'b')
    sum =0
    for idx in range(0,len(b)):
        if b[idx] == '1':
            powerNum = 3 ** (idx+1)
            sum +=powerNum
    answer = sum
    return answer