# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # leftSubTreeMaxDepth = 0
        # rightSubTreeMaxDepth = 0
        # print(root)
        # if root.left is None:
        #     leftSubTreeMaxDepth = 0
        # else:
        #     leftSubTreeMaxDepth = self.maxDepth(root.left)
        # if root.right is None:
        #     rightSubTreeMaxDepth = 0
        # else:
        #     rightSubTreeMaxDepth = self.maxDepth(root.right)
        # result = max(leftSubTreeMaxDepth, rightSubTreeMaxDepth) +1
        
        # return result
        
        
        if root is None:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right))+1
        