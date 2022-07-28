# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
import json
import copy

IMPOSSIBLE_VALUE = -2000

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return None

        treeNodeDict = copy.deepcopy(root.__dict__)
        treeNodeDict['left'] = self.serialize(treeNodeDict['left'])
        treeNodeDict['right'] = self.serialize(treeNodeDict['right'])
        return json.dumps(treeNodeDict)

    def dictToClass(self, my_dict):
        treeNode = TreeNode(IMPOSSIBLE_VALUE)
        for key in my_dict:
            setattr(treeNode, key, my_dict[key])
        return treeNode

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data is None:
            return None
        treeNodeDict = json.loads(data)

        if treeNodeDict['left'] is not None:
            treeNodeDict['left'] = self.deserialize(treeNodeDict['left'])
        if treeNodeDict['right'] is not None:
            treeNodeDict['right'] = self.deserialize(treeNodeDict['right'])
        return self.dictToClass(treeNodeDict)



# Your Codec object will be instantiated and called as such:
ser = Codec()
deser = Codec()
root = TreeNode(3)
sub1 = TreeNode(2)
sub2 = TreeNode(1)
root.left= sub1
root.right = sub2
print(root)
ans = deser.deserialize(ser.serialize(root))
print(root)

root = None
ans = deser.deserialize(ser.serialize(root))
print(ans)