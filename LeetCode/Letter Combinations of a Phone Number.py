class Solution:

    def chooseNumbers(self,chosenNumber:int, makingInfo):
        if chosenNumber == len(self.gDigits):
            self.numberList.append(makingInfo)
            return
        else:
            for letters in self.mapDict[int(self.gDigits[chosenNumber])]:
                makingInfo += letters
                self.chooseNumbers(chosenNumber+1, makingInfo)
                makingInfo = makingInfo[:-1]

    def letterCombinations(self, digits: str) -> List[str]:
        self.numberList = []
        self.mapDict = {2:"abc", 3:"def", 4:"ghi", 5:"jkl", 6:"mno", 7:"pqrs", 8:"tuv", 9:"wxyz"}
        self.gDigits = digits
        self.chooseNumbers(0,"")

        print(self.numberList)


solution = Solution()
solution = 