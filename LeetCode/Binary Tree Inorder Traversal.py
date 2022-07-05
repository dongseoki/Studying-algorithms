# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
#         # L V R
#         tempList = []

#         if root is None:
#             return []

#         if root.left is not None:
#             tempList.extend(self.inorderTraversal(root.left))

#         tempList.append(root.val)

#         if root.right is not None:
#             tempList.extend(self.inorderTraversal(root.right))

#         return tempList

from collections import deque
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # L V R
        if root is None:
            return []
        res = []
        stack = []
        curr = root

        while curr or len(stack) >0:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            res.add(curr.val)
            curr = curr.right

        return res