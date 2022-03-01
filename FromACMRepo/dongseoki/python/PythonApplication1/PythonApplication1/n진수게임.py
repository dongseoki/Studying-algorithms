
def turnNumber(n, k):
    answer = ''
    if n == 0:
        return '0'
    while(True):
        if n<=0 :
            break
        d = n/k
        r = n%k
        if r < 10 :
            answer = str(int(r)) + answer
        else : 
            ch = (r-10) + 65
            answer = chr(ch)+ answer
        n = int(d)
    return answer

def makeAnString (t, m, n):
    limit = t * (m+2)
    anstr = ''
    for i in range(100000):
        anstr += turnNumber(i, n)
        if len(anstr) > limit :
            break
    asdf = len(anstr)

    return anstr

def solution(n, t, m, p):
    answer = ''
    anstr = makeAnString(t,m, n)
    idx = p-1
    result = ''
    for i in range(t):
        result += anstr[idx]
        idx += m
    return result

print(solution(2,1000,100,100))