from itertools import permutations

def checkBanned(item1, banId):
    if len(item1) != len(banId):
        return False
    for idx in range(len(item1)):
        if item1[idx] == banId[idx] or banId[idx] == '*':
            continue
        else:
            return False
    return True


def checkSatisfied(item, banned_id):
    if len(item) != len(banned_id):
        return False
    for (item1, item2) in zip(item, banned_id):
        if checkBanned(item1, item2):
            continue
        else:
            return False
    return True

def solution(user_id, banned_id):
    answer = 0

    # 로직.
    # 순서가 있게 , len(banned_id) 만큼 뽑음.
    # 순서 있게 뽑은 것으로 전부 만족 여부 체크.
    # 체크 후, 정렬후, tuple로 셋에 저장.
    # 저장된 셋에 있는 것 개수 세서 반환.
    # end.

    # 순서가 있게 , len(banned_id) 만큼 뽑음.
    perm = list(permutations(user_id, len(banned_id)))

    answer_set = set()
    for item in perm:
    # 순서 있게 뽑은 것으로 전부 만족 여부 체크.
    # 체크 후, 정렬후, tuple로 셋에 저장.
        # print(item)
        if checkSatisfied(item, banned_id):
            answer_set.add(tuple(sorted(list(item))))

    # 저장된 셋에 있는 것 개수 세서 반환.
    answer = len(answer_set)
    return answer


print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "abc1**"]	))