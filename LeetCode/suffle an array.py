import random
import copy
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.shuffleList = copy.deepcopy(nums)

    def reset(self) -> List[int]:
        self.shuffleList = copy.deepcopy(self.nums)
        return self.shuffleList

    def shuffle(self) -> List[int]:
        random.shuffle(self.shuffleList)
        return self.shuffleList
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()