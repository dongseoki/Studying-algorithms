def solution(people, limit):
    people.sort()
    people.reverse()
    maxWeightIdx = 0
    minWeightIdx = len(people)-1
    contain2PeopleNum = 0
    while( maxWeightIdx < minWeightIdx):
        if people[maxWeightIdx] + people[minWeightIdx] <= limit:
            contain2PeopleNum+=1
            minWeightIdx-=1
        maxWeightIdx+=1
    return len(people) - contain2PeopleNum