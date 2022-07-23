class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numCountList = [0,0,0]
        for numItem in nums:
            numCountList[numItem] +=1

        tempList = []
        for idx, numCountValue in enumerate(numCountList):
            tempList.extend([idx] * numCountValue)

        for idx in range(len(nums)):
            nums[idx]=tempList[idx]


