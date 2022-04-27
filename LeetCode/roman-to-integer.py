class Solution:
    def romanToInt(self, s: str) -> int:
        symbolDict = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        
        total = 0
        idx = 0
        while(idx<len(s)):
            if idx+1 < len(s) and symbolDict[s[idx]] < symbolDict[s[idx+1]]:
                total += symbolDict[s[idx+1]] - symbolDict[s[idx]]
                idx +=2
                continue
            else :
                total +=s[idx]
                idx+=1
        print(s)