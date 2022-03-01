import math
def JinSuConvert(n, k):
    test = ''

    while n > 0:
        temp = n
        n = temp//k
        res = temp%k

        test = str(res) + test

    return test

def makeEratosthenes_che(n, eratosthenes_che_list):
    eratosthenes_che_list[1] = False
    end = int(math.sqrt(n))
    for i in range(2, end + 1):
        if eratosthenes_che_list[i]:    
            for num in range(i*2, n, i): 
                eratosthenes_che_list[num] = False

def solution(n, k, converted_n):
    eratosthenes_che_list = [True] * n
#     converted_n = JinSuConvert(n,k)
    itemList = converted_n.split('0')
    makeEratosthenes_che(n, eratosthenes_che_list)
    answer = 0
    for testNum in itemList:
        if testNum != '' and eratosthenes_che_list[int(testNum)]:
            answer +=1
    return answer

def solution(n, k):
    eratosthenes_che_list = [True] * 10000000
    converted_n = JinSuConvert(n,k)
    itemList = converted_n.split('0')
    makeEratosthenes_che(10000000, eratosthenes_che_list)
    len_eratosthenes_che_list = len(eratosthenes_che_list)
    answer = 0
    for testNum in itemList:
        try:
            if testNum != '' and eratosthenes_che_list[int(testNum)]:
                answer +=1
        except IndexError:
            print('test')
            print('error')

    return answer

solution(1000000,9)