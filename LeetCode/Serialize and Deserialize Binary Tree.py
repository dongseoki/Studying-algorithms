# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        answer = 'None'
        if root is None:
            return answer

        leftSeriResult = ''
        rightSeriResult = ''
        leftSeriResult = self.serialize(self.left)
        rightSeriResult = self.serialize(self.right)

        answer = '{'+ leftSeriResult + '|' + str(self.val)+ '|' + rightSeriResult + '}'
        return answer


    def catchLVR(self, data):
        content = data[1:-1]

        idx = 0
        while True:
            if data[idx]

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data is 'None':
            return []
        deLeft, deValue, deRight = self.catchLVR(data)
        root = TreeNode(int(deValue))
        if deLeft is '':
            root.left = self.deserialize(self.left)
        if deRight is '':
            root.right = self.deserialize(self.right)

        return TreeNode(treeData)



# Your Codec object will be instantiated and called as such:
root = TreeNode(2)
sub1 = TreeNode(3)
sub2 = TreeNode(4)
root.left = sub1
root.right = sub2
print(root)

ser = Codec()
deser = Codec()
ans = deser.deserialize(ser.serialize(root))

print(ans)