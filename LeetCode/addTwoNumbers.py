# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def makeInteger(self, sNode:ListNode) -> int:
        numStr = ''
        while sNode is not None:
            numStr = str(sNode.val) + numStr
            sNode = sNode.next
        return int(numStr)

    def makeLinkedList(self, num) -> ListNode:
        root = ListNode(val=int(str(num)[0]))
        for item in list(map(int,list(str(num))))[1:]:
            newNode = ListNode(val=item)
            newNode.next = root
            root = newNode
        return root

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = self.makeInteger(l1)
        num2 = self.makeInteger(l2)
        return self.makeLinkedList(num1+num2)


