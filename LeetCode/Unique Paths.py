import sys
sys.setrecursionlimit(100000)
class Solution:
    def __init__(self) -> None:
        self.dpDict =  {}

    def caculateCombi(self,n,r):
        if (n,r) in self.dpDict:
            return self.dpDict[(n,r)]
        if (n,n-r) in self.dpDict:
            return self.dpDict[(n,n-r)]
        if r==0:
            return 1
        if n==1 and r==1:
            return 1
        result = self.caculateCombi(n-1,r-1) + self.caculateCombi(n-1,r)
        self.dpDict[(n,r)] = result
        return result
    def uniquePaths(self, m: int, n: int) -> int:
        return self.caculateCombi(m+n-2,min(m-1,n-1))


solution = Solution()
print(solution.uniquePaths(3,7))