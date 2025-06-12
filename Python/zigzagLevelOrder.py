import collections
class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def zigzagLevelOrder(self, root):
        res = []
        q = collections.deque([root] if root else[])
        while q:
            level = []
            for i in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level = list(reversed(level)) if len(res) % 2 else level # reverse if odd else even level
            res.append(level)
        return res