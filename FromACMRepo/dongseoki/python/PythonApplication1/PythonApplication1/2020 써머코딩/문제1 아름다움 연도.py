def beautifulCheck(p):
    numbers = [i*0 for i in range(10)]
    strp = str(p)
    for idx in range(len(strp)):
        num = int(strp[idx])
        numbers[num] +=1
        if numbers[num] > 1:
            return False
    return True

def solution(p):
    num = p+1
    while True :
        if beautifulCheck(num)==True :
            break
        else :
            num +=1

        
    answer = num
    return answer
