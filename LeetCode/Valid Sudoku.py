from typing import List
class Solution:
    def isItValidList(self, testList:List[str]) -> bool:
        numCntList = [0 for _ in range(10)]
        for item in testList:
            if item.isdigit() == True:
                numCntList[int(item)] +=1
        
        for item in numCntList:
            if item >1:
                return False
        return True
    
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # check each columns

        for col in range(9):
            testList = []
            for row in range(9):
                testList.append(board[row][col])
                if self.isItValidList(testList) == False:
                    return False
        
        # check each rows
        for row in range(9):
            testList = []
            if self.isItValidList(board[row]) == False:
                return False
        
        # check each sub-box
        
        testPoints = [ (i,j) for j in range(0,9,3) for i in range(0,9,3)]
        for startPoint in testPoints:
            testList = []
            for i in range(3):
                for j in range(3):
                    testList.append(board[startPoint[0]+i][startPoint[1]+j])
            if self.isItValidList(testList) == False:
                return False
        
        return True
                    
board = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
solution = Solution()
print(solution.isValidSudoku(board))

board =[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

print(solution.isValidSudoku(board))