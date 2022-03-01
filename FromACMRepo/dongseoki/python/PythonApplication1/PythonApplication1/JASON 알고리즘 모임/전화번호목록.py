def solution(phone_book):
    answer = True
    #print(phone_book)
    phone_book.sort()
    #print(phone_book)
    idx =0
    while idx<(len(phone_book) -1 ):
        if phone_book[idx] in phone_book[idx+1]:
            return False
        idx+=1
    return True

print(solution(['119', '97674223', '1195524421']))
print(solution(['123', '456', '789']))
print(solution(['12', '123', '1235', '567', '88']))