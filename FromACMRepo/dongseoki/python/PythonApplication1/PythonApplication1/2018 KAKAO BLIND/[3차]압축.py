
def findLongStr(start, msg, wordDict):
    end = len(msg)
    while True:
        try:
            wordDict[msg[start:end]]
            break
        except KeyError:
            end -= 1
            continue

    return msg[start:end]

# 가장 긴 문자열을 반환 하는 함수.

def solution(msg):
    answer = []
    wordDict = {}
    for i in range(26):
        word = chr(65 + i)
        wordDict[word] = i+1
    #1.    길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.

    start = 0
    while True:
        longStr = findLongStr(start, msg, wordDict)
        #2.사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.

        answer.append(wordDict[longStr])
        # 색인 번호를 붙여넣고
        start += len(longStr)
        # 입력에서 w를 제거 -> start를 그 문자열의 길이만큼 증가시켜 w를 건너뜀.
        #3.w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.


        if start < len(msg) :
            wordCnt = len(wordDict)
            wordDict[longStr+msg[start]] = wordCnt +1
        #입력에서 처리되지 않은 다음 글자가 남아있다면(c) -> start가 len(msg)보다 크거나 같다.
        #4-1.입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
        else :
            break
        #4-2 남아있지 않다면 종료.
        #5.단계 2로 돌아간다.
    return answer

print(solution('KAKAO'))