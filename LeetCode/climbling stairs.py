import sys
sys.setrecursionlimit(20000)
class Solution:
    def __init__(self) -> None:
        self.clibDict = {}

    def climbStairs(self, n: int) -> int:
        if n in self.clibDict:
            return self.clibDict[n]
        if n <=2:
            return n
        result = self.climbStairs(n-1) + self.climbStairs(n-2)
        self.clibDict[n]=result
        return result

for i in range(10):
    test = Solution()
    print(i, test.climbStairs(i))