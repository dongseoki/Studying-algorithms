def solution(phone_numbers, phone_owners, number):
    try:
        resultIdx = phone_numbers.index(number)
    except:
        return number
    return  phone_owners[resultIdx]