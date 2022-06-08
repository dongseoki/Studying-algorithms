class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        sum = 0
        pos = 0
        for idx in range(len(columnTitle)-1,-1,-1):
            sum += 26**pos * (ord(columnTitle[idx])-ord('A')+1)
            pos +=1
        return sum


solution = Solution()
print(solution.titleToNumber('ZY'))
print(solution.titleToNumber('A'))
print(solution.titleToNumber('AB'))